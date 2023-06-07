#include "mediator.h"

#include "sceneloadcontrollercreator.h"
#include "drawmanagercreator.h"

void Mediator::addCamera(const double x, const double y, const double z)
{
	Point cam_pos(x, y, z);

	std::shared_ptr<Camera> cam(new Camera(cam_pos));

	auto scene_manager = SceneManagerCreator().createManager();
	scene_manager->getScene()->getSceneImplementor()->addCamera(cam);
	scene_manager->setCamera(scene_manager->getScene()->getSceneImplementor()->getCameras().size() - 1);
}

void Mediator::removeCamera(const std::size_t &number)
{
	SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->removeCamera(number);
}

void Mediator::transformCamera(const double x, const double y, const std::size_t &cam_number)
{
	auto camera = SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getCameras().at(cam_number);
	TransformManagerCreator().createManager()->moveObject(camera, x, y, 0);
}

void Mediator::setCamera(const std::size_t &cam_number)
{
	SceneManagerCreator().createManager()->setCamera(cam_number);
}

void Mediator::transformModel(const Point &move, const Point &scale, const Point &rotate, const std::size_t &model_numb)
{
	std::shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getModels().at(model_numb);
	TransformManagerCreator().createManager()->moveObject(model, move.getX(), move.getY(), move.getZ());
	TransformManagerCreator().createManager()->scaleObject(model, scale.getX(), scale.getY(), scale.getZ());
	TransformManagerCreator().createManager()->rotateObject(model, rotate.getX(), rotate.getY(), rotate.getZ());
}

void Mediator::transformModel(const BaseMatrix &mtr, const std::size_t &model_numb)
{
	std::shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getModels().at(model_numb);
	TransformManagerCreator().createManager()->transformObject(model, mtr.getMatrix());
}

void Mediator::loadModel(std::string fname)
{
	auto controller = ModelLoadControllerCreator().createController(fname);
	auto manager = LoadManagerCreator().createManager(controller);

	auto model = manager->load(fname);
	SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->addModel(model);
}

void Mediator::addModel(std::shared_ptr<Object> model)
{
	SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->addModel(model);
}

void Mediator::removeModel(const std::size_t &model_numb)
{
	SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->removeModel(model_numb);
}

void Mediator::rotateCamera(const double shift, const std::size_t &cam_number)
{
	auto camera = SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getCameras().at(cam_number);
	TransformManagerCreator().createManager()->rotateObject(camera, shift, shift, 0);
}

std::size_t Mediator::count(bool flag)
{
	if (flag)
		return SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getModels().size();

	return SceneManagerCreator().createManager()->getScene()->getSceneImplementor()->getCameras().size();
}

void Mediator::loadScene(std::string fname)
{
	auto controller = SceneLoadControllerCreator().createController();
	auto manager = LoadManagerCreator().createManager(controller);
	auto scene = std::dynamic_pointer_cast<Scene>(manager->load(fname));
	SceneManagerCreator().createManager()->setScene(scene);
}

void Mediator::drawScene(std::shared_ptr<AbstractDrawer> &drawer)
{
	auto draw_manager = DrawManagerCreator().createManager();
	auto scene_manager = SceneManagerCreator().createManager();
	drawer->clearScene();
	draw_manager->setDrawer(drawer);
	draw_manager->setCameras(scene_manager->getCamera());
	scene_manager->getScene()->getSceneImplementor()->getComposite()->accept(draw_manager);
}
