#include "D3D.h"

using namespace Render::D3D;

Interface::Interface(HWND hWnd, Engine::WindowParams* wp)
{
	// Create the Direct3D interface
	m_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !wp->fullscreen;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	if (!wp->vsync)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	if (wp->fullscreen)
	{
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferWidth = wp->width;
		d3dpp.BackBufferHeight = wp->height;
	}

	m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_d3ddev);
}

Interface::~Interface()
{
	// Release
	m_d3ddev->Release();
	m_d3d->Release();

}

void Interface::BeginScene()
{
	// Overloaded BeginScene, clear by default
	BeginScene(true);
}

void Interface::BeginScene(bool clear)
{
	// Clear the back buffer to #00000
	if (clear)
		m_d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	// Start the scene
	m_d3ddev->BeginScene();
}

/*
	Rendering goes here between
*/

void Interface::EndScene()
{
	// End drawing the scene
	m_d3ddev->EndScene();
}

void Interface::Render()
{
	// Render the scene
	m_d3ddev->Present(NULL, NULL, NULL, NULL);
}