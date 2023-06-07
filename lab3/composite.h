#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
public:
	Composite() = default;
	explicit Composite(std::shared_ptr<Object> &component);
	explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

	std::size_t size() const;

	bool add(const std::shared_ptr<Object> &component) override;
	bool remove(const Iterator &iterator) override;

	Iterator begin() override;
	Iterator end() override;

	Point getCenter() const override {};

	bool isVisible() override;
	bool isComposite() override;
	void transform(const Matrix<double> &mtr, const Point &center) override;
	void accept(std::shared_ptr<Visitor> visitor) override;

	std::vector<std::shared_ptr<Object>> &getObjects();

private:
	std::vector<std::shared_ptr<Object>> objects;
};

#endif // COMPOSITE_H
