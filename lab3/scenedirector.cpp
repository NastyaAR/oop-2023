#include "scenedirector.h"

SceneDirector::SceneDirector()
{
	loader = std::make_shared<FileModelLoader>();
}

SceneDirector::SceneDirector(std::shared_ptr<FileModelLoader> &loader)
{
	this->loader = loader;
}

std::shared_ptr<Object> SceneDirector::create(std::shared_ptr<SceneBuilder> builder)
{
	loader->open(loader->getFileName());

	builder->build();

	loadModels(builder);
	loadCameras(builder);

	loader->close();

	return builder->getObject();
}

void SceneDirector::loadModels(std::shared_ptr<SceneBuilder> builder)
{
	size_t modelsCount = loader->loadCount();

	auto modBuilder = std::make_shared<ModelBuilder>();

	for (size_t i = 0; i < modelsCount; i++)
	{
		auto model = ModelDirector(loader).create(modBuilder);
		builder->buildModel(model);
	}
}

void SceneDirector::loadCameras(std::shared_ptr<SceneBuilder> builder)
{
	size_t camsCount = loader->loadCount();

	auto camBuilder = std::make_shared<CameraBuilder>();

	for (size_t i = 0; i < camsCount; i++)
	{
		auto camera = CameraDirector(loader).create(camBuilder);
		builder->buildCamera(camera);
	}
}

