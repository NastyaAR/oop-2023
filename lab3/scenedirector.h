#ifndef SCENEDIRECTOR_H
#define SCENEDIRECTOR_H

#include "basedirector.h"
#include "filemodelloader.h"
#include "scenebuilder.h"
#include "modeldirector.h"
#include "camerabuilder.h"
#include "cameradirector.h"

class SceneDirector : public BaseDirector
{
public:
	SceneDirector();
	explicit SceneDirector(std::shared_ptr<FileModelLoader> &loader);
	~SceneDirector() = default;

	std::shared_ptr<Object> create(std::shared_ptr<SceneBuilder> builder);

protected:
	virtual void loadModels(std::shared_ptr<SceneBuilder> builder);
	virtual void loadCameras(std::shared_ptr<SceneBuilder> builder);

	std::shared_ptr<FileModelLoader> loader;
};

#endif // SCENEDIRECTOR_H
