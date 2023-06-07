#include "sceneloadcontroller.h"

#include <error.h>

SceneLoadController::SceneLoadController(std::shared_ptr<SceneDirector> director) :
	builder(new SceneBuilder)
{
	this->director = director;
}

std::shared_ptr<Object> SceneLoadController::load(std::string &fname)
{
	std::shared_ptr<Object> scene;

	try
	{
		scene = director->create(builder);
	}
	catch (SourceError &error)
	{
		std::string msg = "Error : Open file";
		throw SourceError(msg);
	}
	catch (std::exception &error)
	{
		std::string msg = "Error : Read model";
		throw SourceError(msg);
	}

	return scene;
}

void SceneLoadController::setDirector(std::shared_ptr<SceneDirector> director)
{
	this->director = director;
}
