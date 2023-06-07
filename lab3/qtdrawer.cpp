#include "qtdrawer.h"

QtDrawer::QtDrawer(QGraphicsScene *scene)  : scene(scene){}

QtDrawer::QtDrawer(const QtDrawer &drawer) : scene(drawer.scene) {}

void QtDrawer::clearScene() {
	scene->clear();
}

void QtDrawer::drawLine(const Point &point1, const Point &point2)
{
	scene->addLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
}
