#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include <cmath>

#include "BaseManager.h"
#include "object.h"
#include "basematrix.h"
#include "scenemanagercreator.h"

class TransformManager : public BaseManager
{
public:
	TransformManager() = default;
	explicit TransformManager(const TransformManager &manager) = delete;
	TransformManager &operator = (const TransformManager &manager) = delete;

	~TransformManager() = default;

	static void moveObject(std::shared_ptr<Object> obj,
						   const double &dx,
						   const double &dy,
						   const double &dz);
	static void scaleObject(std::shared_ptr<Object> obj,
							const double &kx,
							const double &ky,
							const double &kz);
	static void rotateObject(std::shared_ptr<Object> obj,
							 const double &ox,
							 const double &oy,
							 const double &oz);

	static void transformObject(std::shared_ptr<Object> obj,
								const BaseMatrix &mtr);
};

#endif // TRANSFORMMANAGER_H
