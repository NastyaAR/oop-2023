#include "loadmanagercreator.h"

std::shared_ptr<LoadManager> LoadManagerCreator::createManager() {
	if (this->manager == nullptr)
		createInstance();

	return this->manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::createManager(const std::shared_ptr<AbstractLoadController> &loader) {
	if (this->manager == nullptr)
		createInstance();

	this->manager->setLoader(loader);

	return this->manager;
}

void LoadManagerCreator::createInstance() {
	static std::shared_ptr<LoadManager> manager(new LoadManager());
	this->manager = manager;
}
