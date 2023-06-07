#ifndef ABSTRACTDRAWER_H
#define ABSTRACTDRAWER_H

#include "point.h"

class AbstractDrawer
{
public:
	AbstractDrawer() = default;
	virtual ~AbstractDrawer() = default;
	virtual void drawLine(const Point &p1, const Point &p2) = 0;
	virtual void clearScene() = 0;
};

#endif // ABSTRACTDRAWER_H
