#include "Background.h"

BackGround::BackGround() : Shader("./Shader/BackGround.vs", "./Shader/BackGround.fs", 2), faces{
		"./Textures/lake/right.tga",
		"./Textures/lake/left.tga",
		"./Textures/lake/top.tga",
		"./Textures/lake/bottom.tga",
		"./Textures/lake/back.tga",
		"./Textures/lake/front.tga"
}
{
	cubeID = loadCubemap(faces);
}

void BackGround::PaintObject()
{
	
}
