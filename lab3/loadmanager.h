#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

#include "abstractloadcontroller.h"
#include "baseloader.h"
#include "BaseManager.h"
#include "model.h"

class LoadManager : public BaseManager {
public:
	LoadManager();
	LoadManager(const LoadManager &) = delete;
	LoadManager &operator=(const LoadManager &) = delete;
	~LoadManager() = default;

	virtual std::shared_ptr<Object> load(std::string &name);
	virtual void setLoader(std::shared_ptr<AbstractLoadController> loader);

private:
	std::shared_ptr<AbstractLoadController> loader;
};

#endif // LOADMANAGER_H
