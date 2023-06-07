#include "scenemanagercreator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::createManager()
{
	if (this->manager == nullptr)
		createInstance();

	return this->manager;
}

void SceneManagerCreator::createInstance()
{
	static std::shared_ptr<SceneManager> manager(new SceneManager());
	this->manager = manager;

}
