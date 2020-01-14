#include "Human.h"

Human::Human(const QString& filePath, int s, Pnt3f p) :Model(filePath, s, p)
{
}

void Human::goForward()
{
	displace.x-= 0.2;
	checkDistance();
}

void Human::goBackward()
{
	displace.x+= 0.2;
	checkDistance();
}

void Human::goLeft()
{
	displace.z+=0.2;
	checkDistance();
}

void Human::goRight()
{
	displace.z-=0.2;
	checkDistance();
}

void Human::checkDistance()
{
	if (displace.z > 1)displace.z = 1;
	if (displace.z < -1)displace.z = -1;
	if (displace.x > 8)displace.x = 8;
	if (displace.x < -8)displace.x = -8;
}
