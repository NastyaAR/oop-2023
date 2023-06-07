#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene.h"
#include "BaseManager.h"
#include "modelloadcontrollercreator.h"
#include "loadmanagercreator.h"

class SceneManager : public BaseManager
{
public:
	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager() = default;

	std::shared_ptr<Scene> getScene() const;
	std::shared_ptr<Camera> getCamera() const;

	void setScene(std::shared_ptr<Scene> scene_);
	void setCamera(const std::size_t &cam_numb);

private:
	std::shared_ptr<Scene> scene;
	std::shared_ptr<Camera> current_cam;
};


#endif // SCENEMANAGER_H
