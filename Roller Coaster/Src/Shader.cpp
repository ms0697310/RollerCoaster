#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_JPEG

#ifndef STB_IMAGE_INCLUDE
#define STB_IMAGE_INCLUDE
#include "stb_image.h"
#endif


Shader::Shader(QString vertexShaderPath, QString fragmentShaderPath, int vboAmount)
	:vertexShaderPath(vertexShaderPath), fragmentShaderPath(fragmentShaderPath), vboAmount(vboAmount)
{
}
void Shader::DimensionTransformation(GLfloat source[], GLfloat target[][4])
{
	//for uniform value, transfer 1 dimension to 2 dimension
	int i = 0;
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			target[j][k] = source[i];
			i++;
		}
}
void Shader::Begin(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();
	for (int i = 0; i < vboAmount; i++) shaderProgram->enableAttributeArray(i);
	GLfloat P[4][4], MV[4][4];
	DimensionTransformation(ProjectionMatrix, P);
	DimensionTransformation(ModelViewMatrix, MV);
	//pass projection matrix to shader
	shaderProgram->setUniformValue("ProjectionMatrix", P);
	//pass modelview matrix to shader
	shaderProgram->setUniformValue("ModelViewMatrix", MV);
}
void Shader::Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	Begin(ProjectionMatrix, ModelViewMatrix);
	PaintObject();
	End();
}
void Shader::End()
{
	for (int i = 0; i < vboAmount; i++) shaderProgram->disableAttributeArray(i);
	vao.release();
	shaderProgram->release();
}
void Shader::PaintObject()
{
	
}

void Shader::Init()
{
	InitShader();
	InitVAO();
	InitVBO();
	InitTexture();
}
void Shader::InitVAO()
{
	// Create Vertex Array Object
	vao.create();
	// Bind the VAO so it is the current active VAO
	vao.bind();
}
void Shader::InitVBO()
{
	
}
void Shader::InitTexture()
{

}
void Shader::InitShader()
{
	// Create Shader
	shaderProgram = new QOpenGLShaderProgram();
	QFileInfo  vertexShaderFile(vertexShaderPath);
	if (vertexShaderFile.exists())
	{
		vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
		if (vertexShader->compileSourceFile(vertexShaderPath))
			shaderProgram->addShader(vertexShader);
		else
			qWarning() << "Vertex Shader Error " << vertexShader->log();
	}
	else
		qDebug() << vertexShaderFile.filePath() << " can't be found";

	QFileInfo  fragmentShaderFile(fragmentShaderPath);
	if (fragmentShaderFile.exists())
	{
		fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
		if (fragmentShader->compileSourceFile(fragmentShaderPath))
			shaderProgram->addShader(fragmentShader);
		else
			qWarning() << "fragment Shader Error " << fragmentShader->log();
	}
	else
		qDebug() << fragmentShaderFile.filePath() << " can't be found";
	shaderProgram->link();
}

GLuint Shader::loadCubemap(const GLchar* faces[6])
{
	GLuint textureID;
	glGenTextures(1, &textureID);

	int width, height, nrChannels;
	unsigned char* image;

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < 6; i++)
	{
		image = stbi_load(faces[i], &width, &height, &nrChannels, 0);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image
		);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}