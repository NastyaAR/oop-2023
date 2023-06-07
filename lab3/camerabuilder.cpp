#include "camerabuilder.h"

bool CameraBuilder::isBuild()
{
	return camera_ptr != nullptr;
}

void CameraBuilder::build()
{
	camera_ptr = std::make_shared<Camera>();
}

void CameraBuilder::buildPosition(double x, double y, double z)
{
	if (isBuild()) {
		Point pos = { x, y, z };
		camera_ptr->getCameraImplementor()->setPosition(pos);
	}
}

std::shared_ptr<Camera> CameraBuilder::getCamera()
{
	return camera_ptr;
}

std::shared_ptr<Object> CameraBuilder::getObject() {}
