#ifndef CAMERAIMPLEMENTOR_H
#define CAMERAIMPLEMENTOR_H

#include "basecameraimplementor.h"

class CameraImplementor : BaseCameraImplementor
{
public:
	CameraImplementor(Point &pos) : position(pos) {};

	void setPosition(const Point &pos) override;
	Point getPosition() override;
	void setAngle(const Point &angle) override;
	Point getAngle() override;

private:
	Point &position;
	Point angle;
};

#endif // CAMERAIMPLEMENTOR_H
