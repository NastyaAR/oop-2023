#ifndef ABSTRACTDRAWERFACTORY_H
#define ABSTRACTDRAWERFACTORY_H

#include <memory>

#include "abstractdrawer.h"

class AbstractDrawerFactory
{
public:
	virtual std::unique_ptr<AbstractDrawer> createGraphics() = 0;
};

#endif // ABSTRACTDRAWERFACTORY_H
