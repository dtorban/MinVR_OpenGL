/*
 * Copyright Regents of the University of Minnesota, 2015.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRVIEWPORTOGL_H_
#define VRVIEWPORTOGL_H_

#include "display/VRDisplayDevice.h"

namespace MinVR {

class VRViewportOgl: public VRDisplayDevice {
public:
	VRViewportOgl(int x, int y, int width, int height);
	virtual ~VRViewportOgl();

	bool isOpen();
	void use(const MinVR::VRDisplayAction& action);
	void finishRendering();

protected:
	void startRendering(const MinVR::VRRenderer& renderer, int x);

private:
	int x, y, width, height;
};

class VRViewportFactoryOgl : public SimpleVRDisplayFactory {
public:
	VRViewportFactoryOgl();
	virtual ~VRViewportFactoryOgl();

	VRDisplayDevice* createDisplay(const std::string type, const std::string name, VRDataIndex& config, VRDisplayDeviceFactory* factory);
};

} /* namespace MinVR */

#endif /* VRVIEWPORTOGL_H_ */
