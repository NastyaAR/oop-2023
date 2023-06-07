#include "transformmanager.h"

void TransformManager::moveObject(std::shared_ptr<Object> obj,
								  const double &dx,
								  const double &dy,
								  const double &dz)
{
	Matrix<double> mtr = Matrix<double>().moveMatrix(dx, dy, dz);

	obj->transform(mtr, obj->getCenter());
}


void TransformManager::scaleObject(std::shared_ptr<Object> obj,
								   const double &kx,
								   const double &ky,
								   const double &kz)
{
	Matrix<double> mtr = Matrix<double>().scaleMatrix(kx, ky, kz);

	obj->transform(mtr, obj->getCenter());
}


void TransformManager::rotateObject(std::shared_ptr<Object> obj,
								   const double &ox,
								   const double &oy,
								   const double &oz)
{
	Matrix<double> mtr = Matrix<double>().rotateMatrix(ox, oy, oz);

	obj->transform(mtr, obj->getCenter());
}

void TransformManager::transformObject(std::shared_ptr<Object> obj,
									   const BaseMatrix &mtr)
{
	obj->transform(mtr.getMatrix(), obj->getCenter());
}

