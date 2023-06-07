#include "drawmanager.h"
#include "model.h"
#include "matrix.h"

void DrawManager::setDrawer(std::shared_ptr<AbstractDrawer> drawer)
{
	this->drawer = std::move(drawer);
}

void DrawManager::setCameras(std::shared_ptr<Camera> new_cam)
{
	cam = std::move(new_cam);
}

void DrawManager::visit(const Model &model)
{
	auto points = model.getModelImplementor()->getStructure()->getPoints();

	auto center = model.getModelImplementor()->getStructure()->getCenter();
	for (auto edge : model.getModelImplementor()->getStructure()->getEdges())
		this->drawer->drawLine(
				proectPoint(points.at(edge.getStartPoint()).getAbsPoint(center)),
				proectPoint(points.at(edge.getFinishPoint())).getAbsPoint(center));
}

Point DrawManager::proectPoint(const Point &point)
{
	Point new_point(point);
	Point cam_pos(cam->getCameraImplementor()->getPosition());
	new_point.setX(new_point.getX() + cam_pos.getX());
	new_point.setY(new_point.getY() + cam_pos.getY());

	return new_point;
}

void DrawManager::visit(const Camera &camera){};
void DrawManager::visit(const Composite &composite){}
