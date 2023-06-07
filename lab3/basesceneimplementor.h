#ifndef BASESCENEIMPLEMENTOR_H
#define BASESCENEIMPLEMENTOR_H

#include "object.h"
#include "camera.h"

class BaseSceneImplementor
{
public:
	BaseSceneImplementor() = default;

	virtual void addModel(const std::shared_ptr<Object> &model) = 0;
	virtual void removeModel(const std::size_t model_index) = 0;
	virtual void addCamera(const std::shared_ptr<Camera> &camera) = 0;
	virtual void removeCamera(const std::size_t cam_index) = 0;
	virtual std::vector<std::shared_ptr<Object>> getModels() = 0;
	virtual std::shared_ptr<Composite> getComposite() = 0;
	virtual std::vector<std::shared_ptr<Camera>> getCameras() = 0;
};

#endif // BASESCENEIMPLEMENTOR_H
