#ifndef QTDRAWERFACTORY_H
#define QTDRAWERFACTORY_H

#include <memory>


#include "abstractdrawerfactory.h"
#include "qtdrawer.h"


class QtDrawerFactory : public AbstractDrawerFactory
{
public:
	explicit QtDrawerFactory(QGraphicsScene *scene);

	std::unique_ptr<AbstractDrawer> createGraphics() override
	{
		return std::unique_ptr<AbstractDrawer>(new QtDrawer(scene));
	}

private:
	QGraphicsScene *scene;
};

#endif // QTDRAWERFACTORY_H
