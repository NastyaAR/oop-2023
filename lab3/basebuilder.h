#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include "object.h"

class BaseBuilder
{
public:
	BaseBuilder() = default;
	~BaseBuilder() = default;

	virtual void build() = 0;
	virtual shared_ptr<Object> getObject() = 0;
	virtual bool isBuild() = 0;
};

#endif // BASEBUILDER_H
