#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "cameraimplementor.h"

class Camera : public InvisibleObject
{
	friend class DrawManager;

public:
	Camera();
	explicit Camera(const Point &pos);
	~Camera() override = default;

	bool isVisible() override;
	bool isComposite() override;

	Point getCenter() const override;
	void transform(const Matrix<double> &mtr, const Point &center) override;
	void accept(std::shared_ptr<Visitor> visitor) override;

	std::shared_ptr<CameraImplementor> getCameraImplementor() override;

private:
	Point position;
	Point angle;
	std::shared_ptr<CameraImplementor> implementor;
};

#endif // CAMERA_H
