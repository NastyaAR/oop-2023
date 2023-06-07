#include "cameradirector.h"

CameraDirector::CameraDirector()
{
	loader = std::make_shared<FileModelLoader>();
}

CameraDirector::CameraDirector(std::shared_ptr<FileModelLoader> &loader)
{
	this->loader = loader;
}

std::shared_ptr<Camera> CameraDirector::create(std::shared_ptr<CameraBuilder> builder)
{
	loader->open(loader->getFileName());

	builder->build();
	Point location = loader->loadPoint();
	Point direction = loader->loadPoint();
	builder->buildPosition(location.getX(), location.getY(), location.getZ());

	loader->close();

	return builder->getCamera();
}

