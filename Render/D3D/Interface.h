#ifndef INTERFACE_H
#define INTERFACE_H

#include <windows.h>
#include <vector>
#include <iostream>

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <DXErr.h>
#pragma comment(lib, "DXErr.lib")
#include <d3dx9core.h>
#pragma comment(lib, "d3dx9d.lib")

#include "../../Engine/Window.h"
#include "RenderQueue.h"
#include "vertex_formats.h"

namespace Render { namespace D3D {
	class Interface
	{
	public:
		LPDIRECT3D9 m_d3d;
		LPDIRECT3DDEVICE9 m_d3ddev;
		LPD3DXSPRITE m_d3dspt;

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
		struct Vertex
		{
			Vertex(){}
			Vertex(float x, float y, float z)
			{
				_x = x;
				_y = y;
				_z = z;
			}
			float _x, _y, _z;
			static const DWORD FVF = D3DFVF_XYZ;
		};

		IDirect3DVertexBuffer9* VB;
		IDirect3DIndexBuffer9* IB;

	};
} }

#endif