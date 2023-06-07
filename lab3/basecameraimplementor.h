#ifndef BASECAMERAIMPLEMENTOR_H
#define BASECAMERAIMPLEMENTOR_H

#include "point.h"

class BaseCameraImplementor
{
public:
	BaseCameraImplementor() = default;

	virtual void setPosition(const Point &pos) = 0;
	virtual Point getPosition() = 0;
	virtual void setAngle(const Point &angle) = 0;
	virtual Point getAngle() = 0;
};

#endif // BASECAMERAIMPLEMENTOR_H
