#ifndef MODELLOADCONTROLLERCREATOR_H
#define MODELLOADCONTROLLERCREATOR_H

#include <memory>

#include "modelloadcontroller.h"

class ModelLoadControllerCreator {
public:
	std::shared_ptr<ModelLoadController> createController(std::string &fname);

private:
	void createInstance(std::string &fname);
	std::shared_ptr<ModelLoadController> controller;
};

#endif // MODELLOADCONTROLLERCREATOR_H
