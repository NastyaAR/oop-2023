#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "basebuilder.h"
#include "scene.h"

class SceneBuilder : BaseBuilder
{
public:
	SceneBuilder() = default;
	~SceneBuilder() = default;

	void build() override;
	void buildModel(const std::shared_ptr<Object> &model);
	void buildCamera(const std::shared_ptr<Camera> &camera);

	std::shared_ptr<Object> getObject() override;
	bool isBuild() override;
private:
	std::shared_ptr<Scene> scene_ptr;
};
#endif // SCENEBUILDER_H
