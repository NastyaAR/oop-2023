#ifndef DRAWMANAGERCREATOR_H
#define DRAWMANAGERCREATOR_H


#include <memory>

#include "drawmanager.h"

class DrawManagerCreator {
public:
	std::shared_ptr<DrawManager> createManager();

private:
	void createInstance();

	std::shared_ptr<DrawManager> manager;
};

#endif // DRAWMANAGERCREATOR_H
