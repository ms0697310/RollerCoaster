#include "Background.h"

BackGround::BackGround() : Shader("./Shader/BackGround.vs", "./Shader/BackGround.fs", 2), faces{
		"./Textures/hill/right.jpg",
		"./Textures/hill/left.jpg",
		"./Textures/hill/top.jpg",
		"./Textures/hill/bottom.jpg",
		"./Textures/hill/back.jpg",
		"./Textures/hill/front.jpg"
		// "./Textures/lake/right.jpg",
		// "./Textures/lake/left.jpg",
		// "./Textures/lake/top.jpg",
		// "./Textures/lake/bottom.jpg",
		// "./Textures/lake/back.jpg",
		// "./Textures/lake/front.jpg"
}
{
	cubeID = loadCubemap(faces);
}

void BackGround::PaintObject()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeID);
	shaderProgram->setUniformValue("skybox", 0);

	// 將值傳給GPU
	vertex_vbo.create();
	vertex_vbo.bind();
	vertex_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vertex_vbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector4D));
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 4, NULL);
	vertex_vbo.release();

	glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
	//glDrawArrays(GL_QUADS, 0, vertices.size());
}

void BackGround::InitVBO()
{
	//const int length = 256;
	//for (int i = -length; i < length; i+=5) {
	//	for (int j = -length; j < length; j+=5) {
	//		vertices << QVector4D(i, j, -length, 1)
	//			<< QVector4D(i+5, j, -length, 1)
	//			<< QVector4D(i+5, j+5, -length, 1)
	//			<< QVector4D(i, j+5, -length, 1);
	//
	//		vertices << QVector4D(i, j, length, 1)
	//			<< QVector4D(i + 5, j, length, 1)
	//			<< QVector4D(i + 5, j + 5, length, 1)
	//			<< QVector4D(i, j + 5, length, 1);
	//
	//		vertices << QVector4D(i, -length, j, 1)
	//			<< QVector4D(i + 5, -length, j, 1)
	//			<< QVector4D(i + 5, -length, j + 5, 1)
	//			<< QVector4D(i, -length, j + 5, 1);
	//
	//		vertices << QVector4D(i, length, j, 1)
	//			<< QVector4D(i + 5, length, j, 1)
	//			<< QVector4D(i + 5, length, j + 5, 1)
	//			<< QVector4D(i, length, j + 5, 1);
	//
	//		vertices << QVector4D(-length, i, j, 1)
	//			<< QVector4D(-length, i + 5, j, 1)
	//			<< QVector4D(-length, i + 5, j + 5, 1)
	//			<< QVector4D(-length, i, j + 5, 1);
	//
	//		vertices << QVector4D(length, i, j, 1)
	//			<< QVector4D(length, i + 5, j, 1)
	//			<< QVector4D(length, i + 5, j + 5, 1)
	//			<< QVector4D(length, i, j + 5, 1);
	//	}
	//}
	float R = 256.0f;//球的半徑
	int statck = 100;//statck：切片----把球體橫向切成幾部分
	float statckStep = (float)(3.14 / statck);//單位角度值
	int slice = 200;//縱向切幾部分
	float sliceStep = (float)(3.14 / slice);//水平圓遞增的角度
	float r0, r1, x0, x1, y0, y1, z0, z1; //r0、r1為圓心引向兩個臨近切片部分表面的兩條線 (x0,y0,z0)和(x1,y1,z1)為臨近兩個切面的點。
	float alpha0 = 0, alpha1 = 0; //前後兩個角度
	float beta = 0; //切片平面上的角度
	//外層迴圈
	for (int i = 0; i < statck; i++) {
		alpha0 = (float)(-3.14 / 2 + (i * statckStep));
		alpha1 = (float)(-3.14 / 2 + ((i + 1) * statckStep));
		y0 = (float)(R * sin(alpha0));
		r0 = (float)(R * cos(alpha0));
		y1 = (float)(R * sin(alpha1));
		r1 = (float)(R * cos(alpha1));
		//迴圈每一層圓
		for (int j = 0; j <= slice * 2; j++) {
			beta = j * sliceStep;
			x0 = (float)(r0 * cos(beta));
			z0 = -(float)(r0 * sin(beta));
			x1 = (float)(r1 * cos(beta));
			z1 = -(float)(r1 * sin(beta));
			vertices << QVector4D(x0, y0, z0, 1) << QVector4D(x1, y1, z1, 1);
		}
	}
}
