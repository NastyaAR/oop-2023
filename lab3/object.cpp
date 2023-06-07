#include "object.h"

Object::Object()
{
	id = nextId++;
}

bool Object::add(const std::shared_ptr<Object> &)
{
	return false;
}

bool Object::remove(const Iterator &)
{
	return false;
}

bool Object::isVisible()
{
	return false;
}

bool Object::isComposite()
{
	return false;
}

Iterator Object::begin()
{
	return Iterator();
}

Iterator Object::end()
{
	return Iterator();
}

std::size_t Object::getId()
{
	return id;
}

std::size_t Object::nextId = 1;

