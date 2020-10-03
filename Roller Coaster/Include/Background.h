#ifndef BACKGROUND_H  
#define BACKGROUND_H
#include <Shader.h>
#include <QString>
#include <vector>
class BackGround:public Shader
{
private:
	QVector<QVector4D> vertices;
	QOpenGLBuffer vertex_vbo;
	const GLchar* faces[6];
	GLuint cubeID;
public:
	BackGround();
	void PaintObject();
	void InitVBO();
};
#endif
