#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QGraphicsScene>

#include "abstractdrawer.h"

class QtDrawer : public AbstractDrawer
{
public:
	QtDrawer() = delete;
	explicit QtDrawer(QGraphicsScene *scene);
	QtDrawer(const QtDrawer &drawer);

	void drawLine(const Point &point1, const Point &point2) override;
	void clearScene() override;

private:
	QGraphicsScene *scene;
};

#endif // QTDRAWER_H
