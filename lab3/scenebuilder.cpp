#include "scenebuilder.h"

bool SceneBuilder::isBuild()
{
	return scene_ptr != nullptr;
}

void SceneBuilder::build()
{
	scene_ptr = std::make_shared<Scene>();
}

void SceneBuilder::buildModel(const std::shared_ptr<Object> &model)
{
	if (isBuild()) {
		scene_ptr->getSceneImplementor()->addModel(model);
	}
}

void SceneBuilder::buildCamera(const std::shared_ptr<Camera> &camera)
{
	if (isBuild()) {
		scene_ptr->getSceneImplementor()->addCamera(camera);
	}
}

std::shared_ptr<Object> SceneBuilder::getObject()
{
	return scene_ptr;
}
