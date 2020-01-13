#pragma once
#include "Shader.h"
class Hill :
	public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
public:
	Hill();
	void PaintObject();
};

