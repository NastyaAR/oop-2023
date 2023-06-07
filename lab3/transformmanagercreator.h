#ifndef TRANSFORMMANAGERCREATOR_H
#define TRANSFORMMANAGERCREATOR_H

#include <memory>

#include "transformmanager.h"

class TransformManagerCreator
{
public:
	std::shared_ptr<TransformManager> createManager();

private:
	void createInstance();
	std::shared_ptr<TransformManager> manager;
};

#endif // TRANSFORMMANAGERCREATOR_H
