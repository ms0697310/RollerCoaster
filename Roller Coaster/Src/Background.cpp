#include "Background.h"

BackGround::BackGround() : Shader("./Shader/BackGround.vs", "./Shader/BackGround.fs", 2), faces{
		// "./Textures/lake/right.tga",
		// "./Textures/lake/left.tga",
		// "./Textures/lake/top.tga",
		// "./Textures/lake/bottom.tga",
		// "./Textures/lake/back.tga",
		// "./Textures/lake/front.tga"
		"./Textures/lake/right.jpg",
		"./Textures/lake/left.jpg",
		"./Textures/lake/top.jpg",
		"./Textures/lake/bottom.jpg",
		"./Textures/lake/back.jpg",
		"./Textures/lake/front.jpg"
}
{
	cubeID = loadCubemap(faces);
}

void BackGround::PaintObject()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeID);
	shaderProgram->setUniformValue("skybox", 0);

	// ±N­È¶Çµ¹GPU
	vertex_vbo.create();
	vertex_vbo.bind();
	vertex_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vertex_vbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector4D));
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 4, NULL);
	vertex_vbo.release();

	glDrawArrays(GL_QUADS, 0, vertices.size());
}

void BackGround::InitVBO()
{
	const int length = 1000;
	for (int x = -length; x >= length; x++) {
		for (int y = -length; y >= length; y++) {
			vertices << QVector4D(x, y, -1000, 1);
		}
	}
}
