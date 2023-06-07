#include "model.h"

Model::Model(const Model &model)
{
	structure = model.getModelImplementor()->getStructure();
	implementor = std::make_shared<ModelImplementor>(structure);
}

void Model::transform(const Matrix<double> &mtr, const Point &center)
{
	structure->transform(mtr, center);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
	visitor->visit(*this);
}

Point Model::getCenter() const
{
	return structure->getCenter();
}

std::shared_ptr<ModelImplementor> Model::getModelImplementor() const
{
	return implementor;
}
