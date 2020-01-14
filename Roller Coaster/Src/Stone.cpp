#include "Stone.h"
#include "Hill.h"
#define PI 3.141592
Stone::Stone(float x, float z): Shader("./Shader/Stone.vs", "./Shader/Stone.fs", 2), x(x), z(z)
{
}
void Stone::InitVBO()
{
	// 計算stone的點的位置與法向量
	GLfloat A[] = { 4, 2, 0.4, 3 };
	GLfloat D[][2] = { {0.05, 0.2}, {0.06, 0.04}, {0.008, 0.008}, {0.08, -0.08} };

	float R = 5.0f;//球的半徑
	int statck = 40;//statck：切片----把球體橫向切成幾部分
	float statckStep = (float)(PI / statck);//單位角度值
	int slice = 50;//縱向切幾部分
	float sliceStep = (float)(PI / slice);//水平圓遞增的角度
	float r0, r1, x0, x1, y0, y1, z0, z1, yy0, yy1; //r0、r1為圓心引向兩個臨近切片部分表面的兩條線 (x0,y0,z0)和(x1,y1,z1)為臨近兩個切面的點。
	float alpha0 = 0, alpha1 = 0; //前後兩個角度
	float beta = 0; //切片平面上的角度
	//外層迴圈
	for (int i = 0; i < statck; i++) {
		alpha0 = (float)(-PI / 2 + (i * statckStep));
		alpha1 = (float)(-PI / 2 + ((i + 1) * statckStep));
		y0 = (float)(R * sin(alpha0));
		r0 = (float)(R * cos(alpha0));
		y1 = (float)(R * sin(alpha1));
		r1 = (float)(R * cos(alpha1));
		std::vector<QVector4D> vertices_part;
		//迴圈每一層圓
		for (int j = 0; j <= slice * 2; j++) {
			beta = j * sliceStep;
			x0 = (float)(r0 * cos(beta)) + x;
			z0 = -(float)(r0 * sin(beta)) + z;
			x1 = (float)(r1 * cos(beta)) + x;
			z1 = -(float)(r1 * sin(beta)) + z;
			yy0 = 0, yy1 = 0;
			for (int i = 0; i < 4; i++) {
				yy0 += A[i] * sin(D[i][0] * x0 + D[i][1] * z0);
				yy1 += A[i] * sin(D[i][0] * x1 + D[i][1] * z1);
			}
			float hillHeight0 = Hill::ComputePoint(x0, z0), hillHeight1 = Hill::ComputePoint(x1, z1);
			yy0 /= R; yy0 += 2 + y0;
			yy1 /= R; yy1 += 2 + y1;
			yy0 = yy0 >= hillHeight0 + 0.5 ? yy0 : hillHeight0 + 0.5;
			yy1 = yy1 >= hillHeight1 + 0.5 ? yy1 : hillHeight1 + 0.5;
			vertices << QVector4D(x0, yy0, z0, 1) << QVector4D(x1, yy1, z1, 1);
			vertices_part.push_back(QVector4D(x0, yy0, z0, 1));
			vertices_part.push_back(QVector4D(x1, yy1, z1, 1));
		}
		int size = vertices_part.size();
		for (int j = 0; j < size; j++) {
			QVector4D V1 = vertices_part[(j + 1) % size] - vertices_part[j];
			QVector4D V2 = vertices_part[(j + 2) % size] - vertices_part[j];
			QVector4D normal_point;
			normal_point.setX(V1.y() * V2.z() - V1.z() * V2.y());
			normal_point.setY(V1.z() * V2.x() - V1.x() * V2.z());
			normal_point.setZ(V1.x() * V2.y() - V1.y() * V2.x());
			if (j % 2 == 0) normal_point *= -1;
			normal << QVector3D(normal_point.x(), normal_point.y(), normal_point.z());
		}
	}
}
void Stone::PaintObject()
{
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

	glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
}
