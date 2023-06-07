#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

class Mediator
{
public:
	void addCamera(const double x, const double y, const double z);
	void addModel(std::shared_ptr<Object> model);
	void loadModel(std::string fname);
	void removeCamera(const std::size_t &number);
	void setCamera(const std::size_t &cam_number);
	void removeModel(const std::size_t &model_numb);
	void transformModel(const Point &move, const Point &scale, const Point &rotate, const std::size_t &model_numb);
	void transformModel(const BaseMatrix &mtr, const std::size_t &model_numb);
	void transformCamera(const double x, const double y, const std::size_t &cam_number);
	void rotateCamera(const double shift, const std::size_t &cam_number);
	std::size_t count(bool flag=false);
	void drawScene(std::shared_ptr<AbstractDrawer> &drawer);
	void loadScene(std::string fname);
};

#endif // MEDIATOR_H
