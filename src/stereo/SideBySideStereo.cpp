/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <stereo/SideBySideStereo.h>
#include "GL/gl.h"

namespace MinVR {

SideBySideStereo::SideBySideStereo() {
}

SideBySideStereo::~SideBySideStereo() {
}

bool SideBySideStereo::isOpen() {
}

void SideBySideStereo::use(const MinVR::VRDisplayAction& action) {
}

void SideBySideStereo::finishRendering() {
	finishRenderingAllDisplays();
}

void SideBySideStereo::startRendering(const MinVR::VRRenderer& renderer,
		int t) {
	glEnable(GL_SCISSOR_TEST);

	int x = getXOffset();
	int y = getYOffset();
	int width = getWidth();
	int height = getHeight();

	glViewport(x,y,width/2,height);
	glScissor(x,y,width/2,height);
	startRenderingAllDisplays(renderer, t);

	glViewport(x+width/2,y,width/2,height);
	glScissor(x+width/2,y,width/2,height);
	startRenderingAllDisplays(renderer, t);
}

} /* namespace MinVR */

