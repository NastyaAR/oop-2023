#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "camera.h"
#include "composite.h"
#include "sceneimplementor.h"

class Scene : public Object {
public:
	Scene() : models(new Composite), cameras(std::vector<std::shared_ptr<Camera>>()) { implementor = std::make_shared<SceneImplementor>(models, cameras); };
	~Scene() override = default;

	bool isVisible() override { return false; };
	bool isComposite() override { return false; };
	Point getCenter() const override;
	std::size_t getId() override;

	std::shared_ptr<SceneImplementor> getSceneImplementor() override;

protected:
	std::shared_ptr<Composite> models;
	std::vector<std::shared_ptr<Camera>> cameras;
	std::shared_ptr<SceneImplementor> implementor;

private:
	void accept(std::shared_ptr<Visitor> visitor) override {};
	void transform(const Matrix<double> &mtr, const Point &center) override {};
};

#endif // SCENE_H
