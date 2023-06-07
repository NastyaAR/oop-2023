#include "sceneloadcontrollercreator.h"

#include <memory>

std::shared_ptr<SceneLoadController> SceneLoadControllerCreator::createController()
{
	if (nullptr == controller)
		createInstance();

	return controller;
}

void SceneLoadControllerCreator::createInstance()
{
	static std::shared_ptr<SceneLoadController> controller;

	if (!controller)
	{
		std::shared_ptr<SceneDirector> director;
		director = std::shared_ptr<SceneDirector>(new SceneDirector);
		controller = std::make_shared<SceneLoadController>(director);
	}

	this->controller = controller;
}

