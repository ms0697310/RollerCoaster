#include "Wave.h"

#if !defined(STB_IMAGE_IMPLEMENTATION) && !defined(STBI_ONLY_JPEG) 
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_JPEG
#include "stb_image.h"
#endif

Wave::Wave()
	: Shader("./Shader/Wave.vs", "./Shader/Wave.fs", 2), time(0)
{
	faces.push_back("./Textures/right.jpg");
	faces.push_back("./Textures/left.jpg");
	faces.push_back("./Textures/top.jpg");
	faces.push_back("./Textures/bottom.jpg");
	faces.push_back("./Textures/back.jpg");
	faces.push_back("./Textures/front.jpg");
	waterCubeID = loadCubemap();
}
void Wave::updateTime(GLfloat t_time)
{
	time = t_time;
}

GLuint Wave::loadCubemap()
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	
	int width, height, nrChannels;
	unsigned char* image;
	
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < faces.size(); i++)
	{
		image = stbi_load(faces[i], &width, &height, &nrChannels, 0);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image
		);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}

void Wave::PaintObject()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, waterCubeID);
	shaderProgram->setUniformValue("WaterCube", 0);

// 計算Wave的點的位置與法向量
	vertices.clear();
	normal.clear();
	GLfloat A[] = { 0.5, 0.1 };
	GLfloat D[][2] = { {1, 1}, {1, 1} };
	GLfloat L[] = { 1, 4 };
	GLfloat S[] = {1.5, 1};
	for (GLfloat xx = -10.0f; xx < 10.0f; xx++) {
		for (GLfloat zz = -10.0f; zz < 10.0f; zz++) {
			for (int mode = 0; mode < 4; mode++) {
				GLfloat x = xx + (mode == 0 || mode == 1 ? 0 : 1);
				GLfloat z = zz + (mode == 0 || mode == 3 ? 0 : 1);
				QVector3D normal_point, point[4];
				GLfloat point_move[][2] = { {0, 0}, {0, -0.5}, {-0.5, 0} };
				for (int move = 0; move < 3; move++) {
					point[move].setX(x + point_move[move][0]), point[move].setZ(z + point_move[move][1]), point[move].setY(5);
					for (int i = 0; i < 2; i++)  point[move].setY(point[move].y() + A[i] * sin(D[i][0] * point[move].x() + D[i][1] * point[move].z() + time * S[i] * (2 * 3.14 / L[i])));
				}
				QVector3D V1 = point[1] - point[0], V2 = point[2] - point[0];
				normal_point.setX(V1.y() * V2.z() - V1.z() * V2.y());
				normal_point.setY(V1.z() * V2.x() - V1.x() * V2.z());
				normal_point.setZ(V1.x() * V2.y() - V1.y() * V2.x());
				vertices << QVector4D(point[0].x(), point[0].y(), point[0].z(), 1);
				normal << normal_point;
			}
		}
	}

// 將值傳給GPU
	vertex_vbo.create();
	vertex_vbo.bind();
	vertex_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vertex_vbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector4D));
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 4, NULL);
	vertex_vbo.release();

	normal_vbo.create();
	normal_vbo.bind();
	normal_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	normal_vbo.allocate(normal.constData(), normal.size() * sizeof(QVector3D));
	shaderProgram->setAttributeArray(1, GL_FLOAT, 0, 3, NULL);
	normal_vbo.release();

	glDrawArrays(GL_QUADS, 0, vertices.size());
}
