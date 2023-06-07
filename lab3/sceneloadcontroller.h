#ifndef SCENELOADCONTROLLER_H
#define SCENELOADCONTROLLER_H

#include "scenebuilder.h"
#include "abstractloadcontroller.h"
#include "baseloader.h"
#include "scenedirector.h"
#include <utility>

class SceneLoadController : public AbstractLoadController {
public:
	SceneLoadController() = default;
	explicit SceneLoadController(std::shared_ptr<SceneDirector> director);

	~SceneLoadController() = default;

	std::shared_ptr<Object> load(std::string &name) override;
	virtual void setDirector(std::shared_ptr<SceneDirector> director);

private:
	std::shared_ptr<SceneBuilder> builder;
	std::shared_ptr<SceneDirector> director;
};

#endif // SCENELOADCONTROLLER_H
