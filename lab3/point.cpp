#include "point.h"

#include <cmath>

#include "point.h"

double toRadians(const double angle)
{
	return angle * (M_PI / 180);
}

Point::Point(const double x, const double y, const double z)
{
	setX(x);
	setY(y);
	setZ(z);
}


Point::Point(const Point &&point) noexcept
{
	setX(point.x);
	setY(point.y);
	setZ(point.z);

	point.~Point();
}


Point &Point::operator=(Point &&point) noexcept
{
	setX(point.x);
	setY(point.y);
	setZ(point.z);

	point.~Point();

	return *this;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}

void Point::setX(const double x)
{
	this->x = x;
}

void Point::setY(const double y)
{
	this->y = y;
}

void Point::setZ(const double z)
{
	this->z = z;
}

bool Point::operator==(const Point &point) const noexcept
{
	return (point.x == x) && (point.y == y) && (point.z == z);
}

bool Point::isEqual(const Point &point) const noexcept
{
	return *this == point;
}

bool Point::operator!=(const Point &point) const noexcept
{
	return !(*this == point);
}

bool Point::isNotEqual(const Point &point) const noexcept
{
	return !(*this == point);
}

Point Point::operator+(const Point &point) const
{
	Point d{*this};

	d.setX(d.x + point.x);
	d.setY(d.y + point.y);
	d.setZ(d.z + point.z);

	return d;
}

Point Point::operator-(const Point &point) const
{
	Point d{*this};

	d.setX(d.x - point.x);
	d.setY(d.y - point.y);
	d.setZ(d.z - point.z);

	return d;
}


void Point::transform(const Matrix<double> &mtr)
{
	Matrix<double> cur_location = {{x, y, z, 1}};
	Matrix<double> new_location = cur_location * mtr;

	x = new_location[0][0];
	y = new_location[0][1];
	z = new_location[0][2];
}

Point Point::getCenter() const
{
	return *this;
}

Point Point::getAbsPoint(const Point &center)
{
	return (*this) + center;
}

