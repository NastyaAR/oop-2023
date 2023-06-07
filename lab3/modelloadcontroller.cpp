#include "modelloadcontroller.h"

#include <error.h>

ModelLoadController::ModelLoadController(std::shared_ptr<ModelDirector> director) :
	builder(new ModelBuilder)
{
	this->director = director;
}

std::shared_ptr<Object> ModelLoadController::load(std::string &fname)
{

	std::shared_ptr<Object> model;

	try
	{
		model = director->create(builder);
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

	return model;
}
