#ifndef WAVE_H  
#define WAVE_H  
#include <Shader.h>
#include <QString>
class Wave:public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
	GLfloat time;
public:
	Wave();
	void updateTime(GLfloat time);
	void PaintObject();
};
#endif
