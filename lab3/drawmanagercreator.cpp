#include "drawmanagercreator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::createManager()
{
	if (this->manager == nullptr)
		createInstance();

	return this->manager;
}

void DrawManagerCreator::createInstance()
{
	static std::shared_ptr<DrawManager> manager(new DrawManager());
	this->manager = manager;
}
