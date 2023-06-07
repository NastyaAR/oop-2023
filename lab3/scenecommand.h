#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include <string>

#include "BaseCommand.h"
#include "abstractdrawer.h"
#include "mediator.h"


class SceneBaseCommand : public BaseCommand {};

class DrawScene : public SceneBaseCommand {
public:
	DrawScene() = delete;
	explicit DrawScene(std::shared_ptr<AbstractDrawer> drawer);
	~DrawScene() = default;

	void execute() override;

private:
	std::shared_ptr<AbstractDrawer> drawer;
	shared_ptr<Mediator> mediator;
};

class LoadScene : public SceneBaseCommand {
public:
	LoadScene() = delete;
	explicit LoadScene(std::string fname);
	~LoadScene() = default;

	void execute() override;

private:
	std::string fname;
	shared_ptr<Mediator> mediator;
};

#endif // SCENECOMMAND_H
