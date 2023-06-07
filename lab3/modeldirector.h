#ifndef MODELDIRECTOR_H
#define MODELDIRECTOR_H

#include "basedirector.h"
#include "filemodelloader.h"

class ModelDirector : public BaseDirector
{
public:
	ModelDirector();
	explicit ModelDirector(std::shared_ptr<FileModelLoader> &loader);

	~ModelDirector() override = default;

	std::shared_ptr<Object> create(std::shared_ptr<ModelBuilder> builder);

protected:
	std::shared_ptr<FileModelLoader> loader;
};

#endif // MODELDIRECTOR_H
