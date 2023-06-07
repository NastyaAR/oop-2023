#include "camera.h"

Camera::Camera(const Point &pos) : position(pos)
{
	this->angle = Point(0, 0, 0);
	implementor = std::make_shared<CameraImplementor>(position);
}

Camera::Camera()
{
	Point pos = Point(0, 0, 0);
	implementor = std::make_shared<CameraImplementor>(pos);
}

void Camera::transform(const Matrix<double> &mtr, const Point &center)
{
	Point diff = Point(0, 0, 0) - center;
	position = position + diff;

	Matrix<double> cur_location = {{position.getX(), position.getY(), position.getZ(), 1}};
	Matrix<double> new_location = cur_location * mtr;

	position = Point(new_location[0][0], new_location[0][1], new_location[0][2]);

	position = position - diff;
}

Point Camera::getCenter() const
{
	return position;
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
	visitor->visit(*this);
}

bool Camera::isVisible()
{
	return false;
}

bool Camera::isComposite()
{
	return false;
}

std::shared_ptr<CameraImplementor> Camera::getCameraImplementor()
{
	return implementor;
}
