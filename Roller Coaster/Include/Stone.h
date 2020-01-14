#pragma once
#include "Shader.h"
#include <vector>
class Stone : public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
	float x, z;
public:
	Stone(float x = 0, float z = 0);
	void InitVBO();
	void PaintObject();
};

