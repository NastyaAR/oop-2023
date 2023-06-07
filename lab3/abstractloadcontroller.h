#ifndef ABSTRACTLOADCONTROLLER_H
#define ABSTRACTLOADCONTROLLER_H

#include <memory>
#include <utility>

#include "basebuilder.h"
#include "baseloader.h"

class AbstractLoadController {
public:
	AbstractLoadController() = default;
	~AbstractLoadController() = default;

	virtual std::shared_ptr<Object> load(std::string &name) = 0;
	virtual void setLoader(std::shared_ptr<BaseLoader> _loader);

protected:
	std::shared_ptr<BaseLoader> loader;
};

#endif // ABSTRACTLOADCONTROLLER_H
