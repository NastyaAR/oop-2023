#include "cameracommand.h"

#include "camera.h"

#include "cameracommand.h"
#include "transformmanagercreator.h"
#include "scenemanagercreator.h"

#define cd const double

AddCamera::AddCamera(cd x, cd y, cd z) : x_pos(x), y_pos(y), z_pos(z) { mediator = std::make_shared<Mediator>(); }

void AddCamera::execute() {
	mediator->addCamera(x_pos, y_pos, z_pos);
}

RemoveCamera::RemoveCamera(const std::size_t &camera_numb) : camera_numb(camera_numb) { mediator = std::make_shared<Mediator>(); }

void RemoveCamera::execute() {
	mediator->removeCamera(camera_numb);
}

MoveCamera::MoveCamera(const std::size_t &cam_number, cd &shift_ox, cd &shift_oy) : cam_number(cam_number), shift_ox(shift_ox), shift_oy(shift_oy) { mediator = std::make_shared<Mediator>(); }

void MoveCamera::execute() {
	mediator->transformCamera(shift_ox, shift_oy, cam_number);
}

RotateCamera::RotateCamera(const std::size_t &cam_number, cd &shift) : cam_number(cam_number), shift(shift) { mediator = std::make_shared<Mediator>(); }

void RotateCamera::execute() {
	mediator->rotateCamera(shift, cam_number);
}

SetCamera::SetCamera(const std::size_t &cam_number) : cam_number(cam_number) { mediator = std::make_shared<Mediator>(); }

void SetCamera::execute() {
	mediator->setCamera(cam_number);
}

CameraCount::CameraCount(std::shared_ptr<size_t> &count) : _count(count) {}

void CameraCount::execute() {
	(*_count) = mediator->count();
}
