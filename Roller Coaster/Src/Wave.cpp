#include "Wave.h"

Wave::Wave()
	: Shader("./Shader/Wave.vs", "./Shader/Wave.fs", 2), time(0)
{
}
void Wave::updateTime(GLfloat t_time)
{
	time = t_time;
}
void Wave::PaintObject()
{
	vertices.clear();
	normal.clear();
	GLfloat A = 1, D0 = 1, D1 = 1, L = 1, S = 1;
	GLfloat w = 2 * 3.14 / L, p = S * w;
	for (GLfloat x = -10.0f; x < 10.0f; x++) {
		for (GLfloat z = -10.0f; z < 10.0f; z++) {
			for (int move = 0; move < 4; move++) {
				GLfloat xx = x + (move == 1 || move == 2 ? 0.5 : -0.5);
				GLfloat zz = z + (move == 0 || move == 1 ? -0.5 : 0.5);
				GLfloat y = A * sin(D0 * xx + D1 * zz + time * p) + 5.0f;
				vertices << QVector4D(xx, y, zz, 1);
				normal << QVector3D(cos(xx), -1, zz);
			}
		}
	}

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
