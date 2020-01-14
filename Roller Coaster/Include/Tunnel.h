#pragma once
#include "Shader.h"
class Tunnel :
	public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
public:
	Tunnel();
	void PaintObject();
	void InitVBO();
	static bool isInTheTunnel(GLfloat, GLfloat, GLfloat);
};

