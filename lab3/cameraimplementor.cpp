#include "cameraimplementor.h"

void CameraImplementor::setPosition(const Point &pos)
{
	position = pos;
}

void CameraImplementor::setAngle(const Point &angle)
{
	this->angle = angle;
}

Point CameraImplementor::getAngle()
{
	return this->angle;
}

Point CameraImplementor::getPosition()
{
	return position;
}
