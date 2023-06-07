#ifndef BASELOADER_H
#define BASELOADER_H

#include <fstream>
#include <string>

#include "basebuilder.h"
#include "myerror.h"
#include "object.h"

class BaseLoader {
public:
	BaseLoader() = default;
	virtual ~BaseLoader() = default;

	virtual void open(std::string &fname) = 0;
	virtual void close() = 0;
};


#endif // BASELOADER_H
