#ifndef BASEMODELIMPLEMENTOR_H
#define BASEMODELIMPLEMENTOR_H

#include "modelstructure.h"

class BaseModelImplementor
{
public:
	BaseModelImplementor() = default;
	virtual const std::shared_ptr<ModelStructure> getStructure() const = 0;
};

#endif // BASEMODELIMPLEMENTOR_H
