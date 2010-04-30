#ifndef RENDER_H
#define RENDER_H

#include <windows.h>
#include <vector>
#include <iostream>

#include "../Engine/Window.h"

namespace Render
{
class Interface
{
public: 
		Interface();
		Interface(Engine::Window* Wind);
		~Interface();

		// Start the scene
		virtual void BeginScene();
		virtual void BeginScene(bool clear);
		// End the scene
		virtual void EndScene();
		// Render the scene
		virtual void Render();
private:
};
}

#endif