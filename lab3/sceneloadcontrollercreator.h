#ifndef SCENELOADCONTROLLERCREATOR_H
#define SCENELOADCONTROLLERCREATOR_H

#include "sceneloadcontroller.h"

class SceneLoadControllerCreator
{
public:
	std::shared_ptr<SceneLoadController> createController();

private:
	void createInstance();

	std::shared_ptr<SceneLoadController> controller;
};

#endif // SCENELOADCONTROLLERCREATOR_H
