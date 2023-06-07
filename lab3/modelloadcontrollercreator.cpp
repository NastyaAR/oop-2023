#include "modelloadcontrollercreator.h"

#include "filemodelloader.h"

std::shared_ptr<ModelLoadController> ModelLoadControllerCreator::createController(std::string &fname)
{
	if (this->controller == nullptr)
		createInstance(fname);

	return this->controller;
}

void ModelLoadControllerCreator::createInstance(std::string &fname)
{
	static std::shared_ptr<ModelLoadController> controller;

	auto reader = std::shared_ptr<FileModelLoader>(new FileModelLoader(fname));
	auto director = std::shared_ptr<ModelDirector>(new ModelDirector(reader));
	controller = std::make_shared<ModelLoadController>(director);

	this->controller = controller;
}
