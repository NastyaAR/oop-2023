#include "abstractloadcontroller.h"

void AbstractLoadController::setLoader(std::shared_ptr<BaseLoader> loader)
{
	this->loader = std::move(loader);
}
