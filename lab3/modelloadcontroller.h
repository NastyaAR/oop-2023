#ifndef MODELLOADCONTROLLER_H
#define MODELLOADCONTROLLER_H

#include "modelbuilder.h"
#include "abstractloadcontroller.h"
#include "baseloader.h"
#include "modeldirector.h"
#include <utility>

class ModelLoadController : public AbstractLoadController
{
public:
	ModelLoadController() = default;
	explicit ModelLoadController(std::shared_ptr<ModelDirector> director);

	~ModelLoadController() = default;

	std::shared_ptr<Object> load(std::string &fileName) override;

private:
	std::shared_ptr<ModelBuilder> builder;
	std::shared_ptr<ModelDirector> director;
};

#endif // MODELLOADCONTROLLER_H
