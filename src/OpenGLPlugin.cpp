/*
 * Copyright Regents of the University of Minnesota, 2015.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0.
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include "plugin/Plugin.h"
#include <iostream>
#include "main/VRPluginInterface.h"
#include "VRViewportOgl.h"

namespace MinVR {

class OpenGLPlugin : public MinVR::Plugin {
public:
	PLUGIN_API OpenGLPlugin() {
		std::cout << "OpenGLPlugin created." << std::endl;
	}
	PLUGIN_API virtual ~OpenGLPlugin() {
		std::cout << "OpenGLPlugin destroyed." << std::endl;
	}
	PLUGIN_API bool registerPlugin(MinVR::PluginInterface *iface)
	{
		std::cout << "Registering OpenGLPlugin with the following interface: " << iface->getName() << std::endl;

		VRPluginInterface* vrInterface = iface->getInterface<VRPluginInterface>();
		if (vrInterface != NULL)
		{
			viewportFactory = new VRViewportFactoryOgl();
			vrInterface->addVRDisplayDeviceFactory(viewportFactory);
			return true;
		}

		return false;
	}
	PLUGIN_API bool unregisterPlugin(MinVR::PluginInterface *iface)
	{
		std::cout << "Unregistering OpenGLPlugin with the following interface: " << iface->getName() << std::endl;
		delete viewportFactory;
		return true;
	}

private:
	VRViewportFactoryOgl* viewportFactory;
};

}

extern "C"
{
	PLUGIN_API MinVR::Plugin* loadPlugin() {
		return new MinVR::OpenGLPlugin();
	}
}

