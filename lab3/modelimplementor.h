#ifndef MODELIMPLEMENTOR_H
#define MODELIMPLEMENTOR_H

#include "basemodelimplementor.h"

class ModelImplementor : BaseModelImplementor
{
public:
	ModelImplementor(std::shared_ptr<ModelStructure> structure) : structure(structure) {};
	const std::shared_ptr<ModelStructure> getStructure() const override;

private:
	std::shared_ptr<ModelStructure> structure;
};

#endif // MODELIMPLEMENTOR_H
