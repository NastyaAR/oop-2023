#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <cstddef>
#include <memory>

#include "BaseCommand.h"
#include "camera.h"
#include "scenemanager.h"
#include "transformmanager.h"
#include "mediator.h"

class CameraBaseCommand : public BaseCommand {};

class AddCamera : public CameraBaseCommand {
public:
	AddCamera() = delete;
	AddCamera(const double x, const double y, const double z);
	~AddCamera() = default;

	void execute() override;

private:
	double x_pos;
	double y_pos;
	double z_pos;

	shared_ptr<Mediator> mediator;
};

class RemoveCamera : public CameraBaseCommand {
public:
	RemoveCamera() = delete;
	explicit RemoveCamera(const std::size_t &camera_numb);
	~RemoveCamera() = default;

	void execute() override;

private:
	std::size_t camera_numb;
	shared_ptr<Mediator> mediator;
};

class MoveCamera : public CameraBaseCommand {
public:
	MoveCamera() = delete;
	MoveCamera(const std::size_t &cam_number, const double &shift_ox, const double &shift_oy);
	~MoveCamera() = default;

	void execute() override;

private:
	std::size_t cam_number;

	double shift_ox;
	double shift_oy;
	shared_ptr<Mediator> mediator;
};

class RotateCamera : public CameraBaseCommand {
public:
	RotateCamera() = delete;
	RotateCamera(const std::size_t &cam_number, const double &shift);
	~RotateCamera() = default;

	void execute() override;

private:
	std::size_t cam_number;
	double shift;
	shared_ptr<Mediator> mediator;
};

class SetCamera : public CameraBaseCommand {
public:
	SetCamera() = delete;
	explicit SetCamera(const std::size_t &cam_number);
	~SetCamera() = default;

	void execute() override;


private:
	std::size_t cam_number;
	shared_ptr<Mediator> mediator;
};

class CameraCount : public CameraBaseCommand {
public:
	CameraCount() = delete;
	explicit CameraCount(std::shared_ptr<size_t> &count);
	~CameraCount() = default;

	void execute() override;

private:
	std::shared_ptr<size_t> &_count;
	shared_ptr<Mediator> mediator;
};

#endif
