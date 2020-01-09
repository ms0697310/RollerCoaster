#ifndef SHADER_H  
#define SHADER_H  
#include <QtGui/QOpenGLFunctions_4_3_Core>
#include <QtGui/QOpenGLVertexArrayObject>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLShader>
#include <QtGui/QOpenGLShaderProgram>
#include <QtOpenGL/QtOpenGL> 
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QFileInfo>
#include <QOpenGLTexture>
#include <QImage>
#include <QDebug>
#include <QString>
class Shader
{
public:
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLShader* vertexShader;
	QOpenGLShader* fragmentShader;
	QOpenGLVertexArrayObject vao;
	QString vertexShaderPath;
	QString fragmentShaderPath;
	int vboAmount;

public:
	Shader(QString vertexShaderPath, QString fragmentShaderPath, int vboAmount);
	void Init();
	void InitVAO();
	virtual void InitVBO();
	virtual void InitTexture();
	void InitShader();
	void DimensionTransformation(GLfloat source[], GLfloat target[][4]);
	void Begin(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix);
	void Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix);
	void End();
	virtual void PaintObject();
};
#endif
