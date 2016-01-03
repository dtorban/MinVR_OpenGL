/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef SIDEBYSIDESTEREO_H_
#define SIDEBYSIDESTEREO_H_

#include "display/VRDisplayDevice.h"

namespace MinVR {

class SideBySideStereo : public VRDisplayDevice {
public:
	SideBySideStereo();
	virtual ~SideBySideStereo();

	bool isOpen();
	void use(const MinVR::VRDisplayAction& action);
	void finishRendering();

protected:
	void startRendering(const MinVR::VRRenderer& renderer, int x);

};

} /* namespace MinVR */

#endif /* SIDEBYSIDESTEREO_H_ */
