#ifndef IRENDERER_H
#define IRENDERER_H

#include <windows.h>
#include <vector>
#include <iostream>

#include "../Engine/Window.h"

namespace Render
{
class IRenderer
{
public: 
		~IRenderer();

		// Start the scene
		virtual void BeginScene() = 0;
		virtual void BeginScene(bool clear) = 0;
		// End the scene
		virtual void EndScene() = 0;
		// Render the scene
		virtual void Render() = 0;
};
}

#endif