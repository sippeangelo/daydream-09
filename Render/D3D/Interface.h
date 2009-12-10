#ifndef INTERFACE_H
#define INTERFACE_H

#include <windows.h>
#include <d3d9.h>
#include <iostream>
#include <DXErr.h>
#pragma comment(lib, "DXErr.lib")
#include <d3dx9core.h>
#pragma comment(lib, "d3dx9d.lib")
#include "../../Engine/Window.h"
#include "vertex_formats.h"

#pragma comment(lib, "d3d9.lib")

namespace Render { namespace D3D {
	class Interface
	{
	public:
		LPDIRECT3D9 m_d3d;
		LPDIRECT3DDEVICE9 m_d3ddev;

		// Initialize D3D
		Interface(HWND hWnd, Engine::WindowParams* wp);
		// Uninitialize and release D3D
		~Interface();

		// Start the scene
		void BeginScene();
		void BeginScene(bool clear);
		// End the scene
		void EndScene();
		// Render the scene
		void Render();
	private:

	};
} }

#endif