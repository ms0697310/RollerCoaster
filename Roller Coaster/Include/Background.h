#ifndef BACKGROUND_H  
#define BACKGROUND_H
#include <Shader.h>
#include <QString>
#include <vector>
class BackGround:public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
	const GLchar* faces[6];
	GLuint cubeID;
public:
	BackGround();
	void PaintObject();
};
#endif
