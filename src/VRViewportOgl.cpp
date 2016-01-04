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

void VRViewportOgl::use(const MinVR::VRDisplayAction& action) {
}

void VRViewportOgl::startRendering(const MinVR::VRRenderer& renderer, int t) {
	glEnable(GL_SCISSOR_TEST);
	int xOffset = x + getParent()->getXOffset();
	int yOffset = y + getParent()->getYOffset();
	int viewportWidth = min(width, getParent()->getWidth()-x);
	int viewportHeight = min(height, getParent()->getHeight()-y);
	glViewport(xOffset, yOffset, viewportWidth, viewportHeight);
	glScissor(xOffset, yOffset, viewportWidth, viewportHeight);
	startRenderingAllDisplays(renderer, t);
}

void VRViewportOgl::finishRendering() {
	finishRenderingAllDisplays();
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

