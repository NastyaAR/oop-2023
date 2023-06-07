#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <memory>

#include <utility>

#include "camera.h"

#include "abstractdrawer.h"
#include "BaseManager.h"
#include "composite.h"
#include "point.h"
#include "visitor.h"


class DrawManager : public Visitor, public BaseManager
{
public:
	DrawManager() = default;
	DrawManager(const DrawManager &) = delete;
	DrawManager &operator=(const DrawManager &) = delete;
	~DrawManager() = default;

	void visit(const Camera &cam) override;
	void visit(const Model &model) override;
	void visit(const Composite &composite) override;

	void setDrawer(std::shared_ptr<AbstractDrawer>);
	void setCameras(std::shared_ptr<Camera>);

private:
	Point proectPoint(const Point &point);
	std::shared_ptr<AbstractDrawer> drawer;
	std::shared_ptr<Camera> cam;
};

#endif // DRAWMANAGER_H
