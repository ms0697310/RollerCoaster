#ifndef WAVE_H  
#define WAVE_H
#include <Shader.h>
#include <QString>
#include <vector>
#include <QGLWidget> 
#include <QtGui>
#include <QtOpenGL>  
#include <GL/GLU.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#include "Utilities/ArcBallCam.H"
#include "Utilities/3DUtils.H"
class Wave:public Shader
{
private:
	QVector<QVector4D> vertices;
	QVector<QVector3D> normal;
	QOpenGLBuffer vertex_vbo;
	QOpenGLBuffer normal_vbo;
	GLfloat time;
	std::vector<const GLchar*> faces;
	GLuint waterCubeID;
public:
	Wave();
	void updateTime(GLfloat time);
	void PaintObject();
	GLuint loadCubemap();
};
#endif
