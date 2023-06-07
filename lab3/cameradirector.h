#ifndef CAMERADIRECTOR_H
#define CAMERADIRECTOR_H

#include "basedirector.h"
#include "filemodelloader.h"
#include "camerabuilder.h"

class CameraDirector : public BaseDirector
{
public:
	CameraDirector();
	explicit CameraDirector(std::shared_ptr<FileModelLoader> &loader);

	~CameraDirector() override = default;

	std::shared_ptr<Camera> create(std::shared_ptr<CameraBuilder> builder);

protected:
	std::shared_ptr<FileModelLoader> loader;
};

#endif // CAMERADIRECTOR_H
