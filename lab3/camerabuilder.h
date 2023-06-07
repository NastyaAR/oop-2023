#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basebuilder.h"
#include "camera.h"

class CameraBuilder : BaseBuilder
{
public:
	CameraBuilder() = default;
	~CameraBuilder() = default;

	void build() override;
	void buildPosition(double x, double y, double z);

	std::shared_ptr<Camera> getCamera();
	bool isBuild() override;
	std::shared_ptr<Object> getObject();
private:
	std::shared_ptr<Camera> camera_ptr;
};

#endif // CAMERABUILDER_H
