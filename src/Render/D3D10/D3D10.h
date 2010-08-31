#ifndef D3D10_H
#define D3D10_H

#include "../IRender.h"

#include "../../Engine/Window.h"

#include <d3d10.h>
#pragma comment (lib, "d3d10.lib")
#include <d3dx10.h>
#pragma comment (lib, "d3dx10.lib")

namespace Render
{
	class D3D10 : public IRender
	{
	public:
		D3D10();
		~D3D10();

		int Initialize(Engine::Window* Window);
		void Render();
	private:
		struct Vertex
		{
			Vertex(){}
			Vertex(float x, float y, float z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}
			float x, y, z;
			//static const DWORD FVF = D3DFVF_XYZ;
		};

		ID3D10Device* m_d3ddev;
		ID3D10RenderTargetView* m_d3drtv;
		IDXGISwapChain* m_dxgiswapchain;
	};
}

#endif