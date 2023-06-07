#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>
#include <QDebug>

#include "point.h"
#include "visitor.h"

class Object;
class SceneImplementor;
class ModelImplementor;
class CameraImplementor;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object
{
public:
	Object();
	virtual ~Object() = default;

	virtual bool add(const std::shared_ptr<Object> &);
	virtual bool remove(const Iterator &);

	virtual bool isVisible();
	virtual bool isComposite();
	virtual Point getCenter() const = 0;

	virtual void transform(const Matrix<double> &mtr, const Point &center) = 0;
	virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

	virtual Iterator begin();
	virtual Iterator end();
	virtual std::size_t getId();

	virtual std::shared_ptr<SceneImplementor> getSceneImplementor() {}
	virtual std::shared_ptr<ModelImplementor> getModelImplementor() const {}
	virtual std::shared_ptr<CameraImplementor> getCameraImplementor() {}

protected:
	std::size_t id;
	static std::size_t nextId;
};

class VisibleObject : public Object {
public:
	VisibleObject() = default;
	~VisibleObject() override = default;

	virtual Point getCenter() const override = 0;

	bool isVisible() override { return true; }
};

class InvisibleObject : public Object {
public:
	InvisibleObject() = default;
	~InvisibleObject() override = default;

	virtual Point getCenter() const override = 0;

	bool isVisible() override { return false; }
};

#endif //OBJECT_H
