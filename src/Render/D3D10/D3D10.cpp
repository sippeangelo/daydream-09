#include "D3D10.h"

namespace Render
{
	D3DXCOLOR d3dcFromCol(Color col)
	{
		float a = 1.0f;
		if (col.a)
			a = col.a;

		return D3DXCOLOR(col.r, col.g, col.b, a);
	}

	D3D10::D3D10() {}
	D3D10::~D3D10() 
	{
		m_dxgiswapchain->SetFullscreenState(FALSE, NULL);

		m_dxgiswapchain->Release();
		m_d3drtv->Release();
		m_d3ddev->Release();
	}

	int D3D10::Initialize(Engine::Window* Window)
	{
		DXGI_SWAP_CHAIN_DESC scd;

		ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

		scd.BufferCount = 1;
		scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		scd.BufferDesc.Width = Window->WindowParams.width;
		scd.BufferDesc.Height = Window->WindowParams.height;
		scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.OutputWindow = Window->hWnd;
		scd.SampleDesc.Count = 1;
		scd.SampleDesc.Quality = 0;
		scd.Windowed = true; // !Window->WindowParams.fullscreen
		scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		D3D10CreateDeviceAndSwapChain(NULL,
			D3D10_DRIVER_TYPE_HARDWARE,
			NULL,
			0,
			D3D10_SDK_VERSION,
			&scd,
			&m_dxgiswapchain,
			&m_d3ddev);

		ID3D10Texture2D* pBackBuffer;
		m_dxgiswapchain->GetBuffer(0, __uuidof(ID3D10Texture2D), (LPVOID*)&pBackBuffer);
		m_d3ddev->CreateRenderTargetView(pBackBuffer, NULL, &m_d3drtv);
		pBackBuffer->Release();

		// Set the render target as the back buffer
		m_d3ddev->OMSetRenderTargets(1, &m_d3drtv, NULL);

		D3D10_VIEWPORT viewport;

		ZeroMemory(&viewport, sizeof(D3D10_VIEWPORT));

		viewport.TopLeftX = 0;
		viewport.TopLeftY = 0;
		viewport.Width = Window->WindowParams.width;
		viewport.Height = Window->WindowParams.height;

		m_d3ddev->RSSetViewports(1, &viewport);

		D3DX10CreateFont(m_d3ddev, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &m_testfont);

		// Store the window pointer for future use
		m_wnd = Window;

		return 0;
	}

	void D3D10::Render()
	{
		Render(Color(0, 0, 0), "");
	}

	void D3D10::Render(Color col, std::string text)
	{
		D3DXCOLOR d3dc = d3dcFromCol(col);
		m_d3ddev->ClearRenderTargetView(m_d3drtv, d3dc);

		// do 3D rendering on the back buffer here

		RECT rc;
		 rc.left=0;
		 rc.right=100;
		 rc.top=0;
		 rc.bottom=100;
		 if (m_testfont->DrawTextA(NULL, text.c_str(), -1, &rc, DT_NOCLIP, D3DXCOLOR(1.0, 1.0, 1.0, 1.0)) == 0)
			MessageBox(NULL, "Fail", "Fail", MB_OK);

		int vsync = 0;
		if (m_wnd->WindowParams.vsync)
			vsync = 1;
		m_dxgiswapchain->Present(vsync, 0);		
	}
}