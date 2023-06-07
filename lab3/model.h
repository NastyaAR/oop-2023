#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <utility>

#include "drawmanager.h"
#include "modelstructure.h"
#include "object.h"
#include "modelimplementor.h"

class Model : public VisibleObject {
	friend void DrawManager::visit(const Model &model);

public:
	Model() : structure(new ModelStructure) { implementor = std::make_shared<ModelImplementor>(structure); }
	explicit Model(std::shared_ptr<ModelStructure> str) : structure(std::move(str)) { implementor = std::make_shared<ModelImplementor>(structure); };
	Model(const Model &model);
	~Model() = default;

	Point getCenter() const override;

	void transform(const Matrix<double> &mtr, const Point &center) override;
	void accept(std::shared_ptr<Visitor> visitor) override;

	std::shared_ptr<ModelImplementor> getModelImplementor() const override;

private:
	std::shared_ptr<ModelStructure> structure;
	std::shared_ptr<ModelImplementor> implementor;
};

#endif // MODEL_H
