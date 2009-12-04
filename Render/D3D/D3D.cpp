#include "D3D.h"

using namespace Render;

D3D::D3D(HWND hWnd, Engine::WindowParams* wp)
{
	// Create the Direct3D interface
	m_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !wp->fullscreen;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	if (wp->fullscreen)
	{
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferWidth = wp->width;
		d3dpp.BackBufferHeight = wp->height;
	}

	m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_d3ddev);

	m_d3ddev->CreateVertexBuffer(3*sizeof(CUSTOMVERTEX),
							   0,
							   CUSTOMFVF,
							   D3DPOOL_MANAGED,
							   &m_vbuffer,
							   NULL);

    // create three vertices using the CUSTOMVERTEX struct built earlier
    CUSTOMVERTEX vertices[] =
    {
        { 0.0f, 0.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { 10.0f, 0.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { 0.0f, 20.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0), },
    };

    VOID* pVoid;    // the void pointer

    m_vbuffer->Lock(0, 0, (void**)&pVoid, 0);    // lock the vertex buffer
    memcpy(pVoid, vertices, sizeof(vertices));    // copy the vertices to the locked buffer
    m_vbuffer->Unlock();    // unlock the vertex buffer
}

D3D::~D3D()
{
	// Release
	m_d3ddev->Release();
	m_d3d->Release();

}

void D3D::BeginScene()
{
	// Overloaded BeginScene, clear by default
	BeginScene(true);
}

void D3D::BeginScene(bool clear)
{
	// Clear the back buffer to #00000
	if (clear)
		m_d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	// Start the scene
	m_d3ddev->BeginScene();

        // select which vertex format we are using
        m_d3ddev->SetFVF(CUSTOMFVF);

        // select the vertex buffer to display
        m_d3ddev->SetStreamSource(0, m_vbuffer, 0, sizeof(CUSTOMVERTEX));

        // copy the vertex buffer to the back buffer
        m_d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

/*
	Rendering goes between those functions
*/

void D3D::EndScene()
{
	// End drawing the scene
	m_d3ddev->EndScene();
}

void D3D::Render()
{
	// Render the scene
	m_d3ddev->Present(NULL, NULL, NULL, NULL);
}