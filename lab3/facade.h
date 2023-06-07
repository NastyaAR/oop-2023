#ifndef FACADE_H
#define FACADE_H

#include <memory>

#include "BaseCommand.h"

class Facade {
public:
	void execute(BaseCommand &cmd);
};

#endif // FACADE_H
