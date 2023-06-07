#include "loadmanager.h"

#include "modelloadcontroller.h"
#include "sceneloadcontrollercreator.h"
#include "filemodelloader.h"
#include <utility>

LoadManager::LoadManager()
{
	loader = SceneLoadControllerCreator().createController();
}

void LoadManager::setLoader(std::shared_ptr<AbstractLoadController> loader)
{
	this->loader = std::move(loader);
}

std::shared_ptr<Object> LoadManager::load(std::string &name) {
	return this->loader->load(name);
}
