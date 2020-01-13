#include "Hill.h"

Hill::Hill()
	: Shader("./Shader/Hill.vs", "./Shader/Hill.fs", 2)
{
}

void Hill::PaintObject()
{
	// 計算Hill的點的位置與法向量
	vertices.clear();
	normal.clear();
	GLfloat A[] = { 5, 3, 2 };
	GLfloat D[][2] = { {0.04, 0.01}, {0.02, 0.05}, {0.003, 0.003} };
	for (GLfloat xx = -100.0f; xx < 100.0f; xx+=10) {
		for (GLfloat zz = -100.0f; zz < 100.0f; zz+=10) {
			for (int mode = 0; mode < 4; mode++) {
				GLfloat x = xx + (mode == 0 || mode == 1 ? 0 : 10);
				GLfloat z = zz + (mode == 0 || mode == 3 ? 0 : 10);
				QVector3D normal_point, point[4];
				GLfloat point_move[][2] = { {0, 0}, {0, -0.5}, {-0.5, 0} };
				for (int move = 0; move < 3; move++) {
					GLfloat tmpY = 0;
					point[move].setX(x + point_move[move][0]), point[move].setZ(z + point_move[move][1]);
					int totalHeight = 0;
					for (int i = 0; i < 2; i++) {
						tmpY += A[i] * sin(D[i][0] * point[move].x() + D[i][1] * point[move].z());
						totalHeight += A[i];
					}
					tmpY += tmpY * ((totalHeight - tmpY > 0 ? tmpY : -tmpY) / totalHeight);
					point[move].setY(tmpY);
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
