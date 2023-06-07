#include "transformmanagercreator.h"

std::shared_ptr<TransformManager> TransformManagerCreator::createManager()
{
	if (this->manager == nullptr)
		createInstance();

	return this->manager;
}

void TransformManagerCreator::createInstance()
{
	static std::shared_ptr<TransformManager> manager(new TransformManager());
	this->manager = manager;
}
