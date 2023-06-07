#include "scenecommand.h"

#include "sceneloadcontrollercreator.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanager.h"
#include "scenemanagercreator.h"
#include <utility>

DrawScene::DrawScene(std::shared_ptr<AbstractDrawer> drawer) : drawer(std::move(drawer)) { mediator = std::make_shared<Mediator>(); }

void DrawScene::execute()
{
	mediator->drawScene(drawer);
}

LoadScene::LoadScene(std::string fname) : fname(std::move(fname)) { mediator = std::make_shared<Mediator>(); }

void LoadScene::execute()
{
	mediator->loadScene(fname);
}
