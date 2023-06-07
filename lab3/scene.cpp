#include "scene.h"

Point Scene::getCenter() const
{
	return Point(0,0,0);
}

std::size_t Scene::getId()
{
	return 0;
}

std::shared_ptr<SceneImplementor> Scene::getSceneImplementor()
{
	return implementor;
}


