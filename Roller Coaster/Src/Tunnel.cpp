#include "Tunnel.h"

Tunnel::Tunnel()
	: Shader("./Shader/Tunnel.vs", "./Shader/Tunnel.fs", 2)
{
}

void Tunnel::PaintObject()
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

	glDrawArrays(GL_QUAD_STRIP, 0, vertices.size());
}

void Tunnel::InitVBO()
{
	GLfloat weight = 15, length = 30, height = 12, arcHeight = 6;
	GLfloat basicX = -50, basicY = -1, basicZ = 50;
	GLfloat detaRange = 3.14 / weight;
	//底
	vertices << QVector4D(0 + basicX, 0 + basicY, 0 + basicZ, 1) << QVector4D(0 + basicX, 0 + basicY, length + basicZ, 1);
	normal << QVector3D(0, 1, 0) << QVector3D(0, 1, 0);

	vertices << QVector4D(weight + basicX, 0 + basicY, 0 + basicZ, 1) << QVector4D(weight + basicX, 0 + basicY, length + basicZ, 1);
	normal << QVector3D(0, 1, 0) << QVector3D(0, 1, 0);

	//右
	vertices << QVector4D(weight + basicX, 0 + basicY, 0 + basicZ, 1) << QVector4D(weight + basicX, 0 + basicY, length + basicZ, 1);
	normal << QVector3D(1, 0, 0) << QVector3D(1, 0, 0);

	vertices << QVector4D(weight + basicX, height + basicY, 0 + basicZ, 1) << QVector4D(weight + basicX, height + basicY, length + basicZ, 1);
	normal << QVector3D(1, 0, 0) << QVector3D(1, 0, 0);

	// 上

	for (GLfloat x = weight; x >= 0 ; x--) {
		GLfloat y = arcHeight * sin(detaRange * x) + height;
		vertices << QVector4D(x + basicX, y + basicY, 0 + basicZ, 1) << QVector4D(x + basicX, y + basicY, length + basicZ, 1);
		GLfloat rate = -arcHeight * cos((detaRange * x));
		normal << QVector3D(rate, 1, 0) << QVector3D(rate, 1, 0);
	}

	// 左
	vertices << QVector4D(0 + basicX, 0 + basicY, 0 + basicZ, 1) << QVector4D(0 + basicX, 0 + basicY, length + basicZ, 1);
	normal << QVector3D(-1, 0, 0) << QVector3D(-1, 0, 0);
}

bool Tunnel::isInTheTunnel(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat weight = 8, length = 88, height = 6, arcHeight = 3;
	GLfloat basicX = 28, basicY = 2, basicZ = -36;
	GLfloat detaRange = 3.14 / weight;
	if (x < basicX || x > basicX + weight) return false;
	if (z < basicZ || z > basicZ + length) return false;
	GLfloat tunnelHeight = arcHeight * sin(detaRange * x) + height + basicY;
	if (y < basicY || y > tunnelHeight) return false;
	return true;
}
