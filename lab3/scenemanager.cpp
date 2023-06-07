#include "scenemanager.h"

#include <memory>
#include <utility>

#include "composite.h"

#include <memory>
#include <utility>

SceneManager::SceneManager() {
	scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene() const {
	return scene;
}

std::shared_ptr<Camera> SceneManager::getCamera() const {
	return current_cam;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene_) {
	scene = std::move(scene_);
}

void SceneManager::setCamera(const std::size_t &number) {
	auto _camera = scene->getSceneImplementor()->getCameras().at(number);
	current_cam = _camera;
}
