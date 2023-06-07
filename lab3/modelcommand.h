#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include "BaseCommand.h"
#include "object.h"
#include "transformmanagercreator.h"
#include "mediator.h"


class ModelBaseCommand : public BaseCommand {};

class MoveModel : public ModelBaseCommand {
public:
	MoveModel() = delete;
	MoveModel(const double &dx, const double &dy, const double &dz, const std::size_t &mnumb);
	~MoveModel() = default;

	void execute() override;

private:
	std::size_t model_numb;

	double dx, dy, dz;
	shared_ptr<Mediator> mediator;
};

class ScaleModel : public ModelBaseCommand {
public:
	ScaleModel() = delete;
	ScaleModel(const double &kx, const double &ky, const double &kz, const std::size_t &mnumb);
	~ScaleModel() = default;

	void execute() override;

private:
	std::size_t model_numb;

	double kx, ky, kz;
	shared_ptr<Mediator> mediator;
};

class RotateModel : public ModelBaseCommand {
public:
	RotateModel() = delete;
	RotateModel(const double &ox, const double &oy, const double &oz, const std::size_t &mnumb);
	~RotateModel() = default;

	void execute() override;

private:
	std::size_t model_numb;

	double ox, oy, oz;
	shared_ptr<Mediator> mediator;
};

class TransformModel : public ModelBaseCommand {
public:
	TransformModel() = delete;
	TransformModel(const std::size_t &numb, BaseMatrix &mtr);
	~TransformModel() = default;

	void execute() override;

private:
	std::size_t model_numb;

	BaseMatrix &mtr;
	shared_ptr<Mediator> mediator;
};

class LoadModel : public ModelBaseCommand {
public:
	LoadModel() = delete;
	explicit LoadModel(std::string fname);
	~LoadModel() = default;

	void execute() override;

private:
	std::string fname;
	shared_ptr<Mediator> mediator;
};

class ExportModel : public ModelBaseCommand {
public:
	ExportModel() = delete;
	explicit ExportModel(std::string fname);
	~ExportModel() = default;

	void execute() override;

private:
	std::string fname;
	shared_ptr<Mediator> mediator;
};

class AddModel : public ModelBaseCommand {
public:
	AddModel() = delete;
	explicit AddModel(std::shared_ptr<Object> model);
	~AddModel() = default;

	void execute() override;

private:
	std::shared_ptr<Object> model;
	shared_ptr<Mediator> mediator;
};

class RemoveModel : public ModelBaseCommand {
public:
	RemoveModel() = delete;
	explicit RemoveModel(const std::size_t &model_numb);
	~RemoveModel() = default;

	void execute() override;

private:
	std::size_t model_numb;
	shared_ptr<Mediator> mediator;
};

class ModelCount : public ModelBaseCommand {
public:
	ModelCount() = delete;
	explicit ModelCount(std::shared_ptr<size_t> &count);
	~ModelCount() = default;

	void execute() override;

private:
	std::shared_ptr<size_t> &_count;
	shared_ptr<Mediator> mediator;
};

#endif
