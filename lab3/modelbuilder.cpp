#include "modelbuilder.h"

void ModelBuilder::buildPoint(const double &x, const double &y, const double &z)
{
	if (isBuild()) {
		Point p = {x, y, z};
		model_ptr->addPoint(p);
	}
}

void ModelBuilder::buildEdge(const std::size_t &point1, const std::size_t &point2)
{
	if (isBuild()) {
		Edge e = {point1, point2};
		model_ptr->addEdge(e);
	}
}

void ModelBuilder::build()
{
	model_ptr = make_shared<ModelStructure>();
}

bool ModelBuilder::isBuild()
{
	return model_ptr != nullptr;
}

std::shared_ptr<Object> ModelBuilder::getObject()
{
	return std::make_shared<Model>(Model(model_ptr));
}
