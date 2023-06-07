#include "modelcommand.h"

#include "modelloadcontrollercreator.h"
#include "loadmanagercreator.h"
#include "transformmanagercreator.h"
#include "scenemanagercreator.h"
#include <utility>

#define cd const double

MoveModel::MoveModel(cd &dx, cd &dy, cd &dz, const std::size_t &mnumb) : dx(dx), dy(dy), dz(dz), model_numb(mnumb) { mediator = std::make_shared<Mediator>(); }

void MoveModel::execute() {
	mediator->transformModel(Point(dx, dy, dz), Point(1, 1, 1), Point(0, 0, 0), model_numb);
}

ScaleModel::ScaleModel(cd &kx, cd &ky, cd &kz, const std::size_t &mnumb) : kx(kx), ky(ky), kz(kz), model_numb(mnumb) { mediator = std::make_shared<Mediator>(); }

void ScaleModel::execute() {
	mediator->transformModel(Point(0, 0, 0), Point(kx, ky, kz), Point(0, 0, 0), model_numb);
}

RotateModel::RotateModel(cd &ox, cd &oy, cd &oz, const std::size_t &mnumb) : ox(ox), oy(oy), oz(oz), model_numb(mnumb) { mediator = std::make_shared<Mediator>(); }

void RotateModel::execute() {
	mediator->transformModel(Point(0, 0, 0), Point(1, 1, 1), Point(ox, oy, oz), model_numb);
}

TransformModel::TransformModel(const std::size_t &numb, BaseMatrix &mtr) : model_numb(numb), mtr(mtr) { mediator = std::make_shared<Mediator>(); }

void TransformModel::execute() {
	mediator->transformModel(mtr, model_numb);
}

LoadModel::LoadModel(std::string fname) : fname(std::move(fname)) { mediator = std::make_shared<Mediator>(); }

void LoadModel::execute() {
	mediator->loadModel(fname);
}

ExportModel::ExportModel(std::string fname) { mediator = std::make_shared<Mediator>(); }

void ExportModel::execute() {
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(std::move(model)) { mediator = std::make_shared<Mediator>(); }

void AddModel::execute() {
	mediator->addModel(model);
}

RemoveModel::RemoveModel(const std::size_t &model_numb) : model_numb(model_numb) { mediator = std::make_shared<Mediator>(); }

void RemoveModel::execute() {
	mediator->removeModel(model_numb);
}

ModelCount::ModelCount(std::shared_ptr<size_t> &count) : _count(count) { mediator = std::make_shared<Mediator>(); }

void ModelCount::execute() {
	(*_count) = mediator->count(true);
}


