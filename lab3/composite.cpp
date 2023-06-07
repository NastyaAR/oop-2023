#include "composite.h"

Composite::Composite(std::shared_ptr<Object> &component)
{
	objects.push_back(component);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector)
{
	objects = vector;
}

std::size_t Composite::size() const
{
	return objects.size();
}

bool Composite::add(const std::shared_ptr<Object> &component)
{
	objects.push_back(component);
	return true;
}

bool Composite::remove(const Iterator &iterator)
{
	objects.erase(iterator);
	return true;
}

Iterator Composite::begin()
{
	return objects.begin();
}

Iterator Composite::end()
{
	return objects.end();
}

bool Composite::isVisible()
{
	return false;
}

bool Composite::isComposite()
{
	return true;
}

void Composite::transform(const Matrix<double> &mtr, const Point &center)
{
	for (auto &el : objects)
		el->transform(mtr, center);
}

std::vector<std::shared_ptr<Object>> &Composite::getObjects()
{
	return objects;
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
	for (const auto &obj : objects) {
		obj->accept(visitor);
	}
}
