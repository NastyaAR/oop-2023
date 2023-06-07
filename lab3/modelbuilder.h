#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "basebuilder.h"
#include "model.h"

class ModelBuilder : public BaseBuilder
{
public:
	ModelBuilder() = default;
	~ModelBuilder() = default;

	void build() override;
	void buildPoint(const double &x, const double &y, const double &z);
	void buildEdge(const std::size_t &point1, const std::size_t &point2);

	std::shared_ptr<Object> getObject() override;
	bool isBuild() override;

private:
	std::shared_ptr<ModelStructure> model_ptr;
};

#endif // MODELBUILDER_H
