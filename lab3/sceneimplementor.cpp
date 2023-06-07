#include "sceneimplementor.h"

void SceneImplementor::addModel(const std::shared_ptr<Object> &model)
{
	models->add(model);
}

void SceneImplementor::removeModel(const std::size_t index)
{
	auto it = models->begin();
	std::advance(it, index);
	models->remove(it);
}

void SceneImplementor::addCamera(const std::shared_ptr<Camera> &camera)
{
	cameras.push_back(camera);
}

void SceneImplementor::removeCamera(const std::size_t index)
{
	auto it = cameras.begin();
	std::advance(it, index);
	cameras.erase(it);
}

std::vector<std::shared_ptr<Object>> SceneImplementor::getModels()
{
	return models->getObjects();
}

std::shared_ptr<Composite> SceneImplementor::getComposite()
{
	return models;
}

std::vector<std::shared_ptr<Camera>> SceneImplementor::getCameras()
{
	return cameras;
}
