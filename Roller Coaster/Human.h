#pragma once
#include "LoadObj/Model.h"
class Human :
	public Model
{
public:
	Human() {};
	Human(const QString& filePath, int s, Pnt3f p);
	void goForward();
	void goBackward();
	void goLeft();
	void goRight();
	void checkDistance();
};

