#ifndef BASECAMERALOADER_H
#define BASECAMERALOADER_H


#include "camerabuilder.h"
#include "baseloader.h"

class BaseCameraLoader : public BaseLoader {
public:
	virtual std::shared_ptr<Object> load(const std::shared_ptr<CameraBuilder> &builder) = 0;
};

#endif // BASECAMERALOADER_H
