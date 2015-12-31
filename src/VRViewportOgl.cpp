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
	renderer.render();
}

void VRViewportOgl::finishRendering() {
}

VRViewportFactoryOgl::VRViewportFactoryOgl() {
}

VRViewportFactoryOgl::~VRViewportFactoryOgl() {
}

std::vector<VRDisplayDevice*> VRViewportFactoryOgl::create(
		VRDataIndex& config, const std::string nameSpace,
		VRDisplayDeviceFactory* factory) {
	std::vector<VRDisplayDevice*> v;
	//v.push_back(new VRViewportOgl(0,0,50,50));
	//v.push_back(new VRViewportOgl(100,100,200,300));
	return v;
}

} /* namespace MinVR */


