#ifndef SCENEIMPLEMENTOR_H
#define SCENEIMPLEMENTOR_H

#include "basesceneimplementor.h"
#include "camera.h"
#include "composite.h"
#include "model.h"

class SceneImplementor : BaseSceneImplementor
{
public:
	SceneImplementor(std::shared_ptr<Composite> models, std::vector<std::shared_ptr<Camera>> cameras) : models(models), cameras(cameras) {};

	void addModel(const std::shared_ptr<Object> &model);
	void removeModel(const std::size_t model_index);
	void addCamera(const std::shared_ptr<Camera> &camera);
	void removeCamera(const std::size_t cam_index);
	std::vector<std::shared_ptr<Object>> getModels();
	std::shared_ptr<Composite> getComposite();
	std::vector<std::shared_ptr<Camera>> getCameras();

private:
	std::shared_ptr<Composite> models;
	std::vector<std::shared_ptr<Camera>> cameras;
};

#endif // SCENEIMPLEMENTOR_H
