/*
 * Copyright Regents of the University of Minnesota, 2015.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include "VRViewportOgl.h"
#include "GL/gl.h"

namespace MinVR {

VRViewportOgl::VRViewportOgl(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
}

VRViewportOgl::~VRViewportOgl() {
}

bool VRViewportOgl::isOpen() {
}

void VRViewportOgl::use(const MinVR::VRDisplayAction& action) {
}

void VRViewportOgl::startRendering(const MinVR::VRRenderer& renderer, int t) {
	glEnable(GL_SCISSOR_TEST);
	glViewport(x,y,width,height);
	glScissor(x,y,width,height);
	startRenderingAllDisplays(renderer, t);
}

void VRViewportOgl::finishRendering() {
	finishRenderingAllDisplays();
}

VRViewportFactoryOgl::VRViewportFactoryOgl() {
}

VRViewportFactoryOgl::~VRViewportFactoryOgl() {
}

VRDisplayDevice* VRViewportFactoryOgl::createDisplay(const std::string type, const std::string name, VRDataIndex& config, VRDisplayDeviceFactory* factory)
{
	if (type == "viewport")
	{
		int width = config.getValue("width", name);
		int height = config.getValue("height", name);

		return new VRViewportOgl(0,0,width,height);
	}

	return NULL;
}

int VRViewportOgl::getXOffset() {
	return x;
}

int VRViewportOgl::getYOffset() {
	return y;
}

int VRViewportOgl::getWidth() {
	return width;
}

int VRViewportOgl::getHeight() {
	return height;
}

} /* namespace MinVR */

