#include "D3D.h"

namespace Render
{

/*D3D::D3D()
{
	std::cout << "D3D Renderer initialized.\n";
}

D3D::D3D(Engine::Window* Window)
{
	D3D();
	std::cout << "Valid HWND: " << IsWindow(Window->hWnd) << "\n";
}

D3D::~D3D()
{

}*/

D3D::D3D(Engine::Window* Window)
{
	// Create the Direct3D interface
	m_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !Window->WindowParams.fullscreen;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = Window->hWnd;
	if (!Window->WindowParams.vsync)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	if (Window->WindowParams.fullscreen)
	{
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferWidth = Window->WindowParams.width;
		d3dpp.BackBufferHeight = Window->WindowParams.height;
	}

	m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window->hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_d3ddev);

	// Initialize sprite to null
	m_d3dspt = NULL;

	// Create a vertex buffer to hold our test cube
	m_d3ddev->CreateVertexBuffer(8 * sizeof(Vertex), D3DUSAGE_WRITEONLY, Vertex::FVF, D3DPOOL_MANAGED, &VB, 0);
	// Index buffer
	m_d3ddev->CreateIndexBuffer(36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &IB, 0);

	// Fill the buffers with the cube data
	Vertex* vertices;
	VB->Lock(0, 0, (void**)&vertices, 0);

	// Vertices of a unit cube
	vertices[0] = Vertex(-1.0f, -1.0f, -1.0f);
	vertices[1] = Vertex(-1.0f, 1.0f, -1.0f);
	vertices[2] = Vertex(1.0f, 1.0f, -1.0f);
	vertices[3] = Vertex(1.0f, -1.0f, -1.0f);
	vertices[4] = Vertex(-1.0f, -1.0f, 1.0f);
	vertices[5] = Vertex(-1.0f, 1.0f, 1.0f);
	vertices[6] = Vertex(1.0f, 1.0f, 1.0f);
	vertices[7] = Vertex(1.0f, -1.0f, 1.0f);

	VB->Unlock();

	// Define the triangles of the cube
	WORD* indices = 0;
	IB->Lock(0, 0, (void**)&indices, 0);

	// Front side
	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	// Back side
	indices[6] = 4; indices[7] = 6; indices[8] = 5;
	indices[9] = 4; indices[10] = 7; indices[11] = 6;

	// Left side
	indices[12] = 4; indices[13] = 5; indices[14] = 1;
	indices[15] = 4; indices[16] = 1; indices[17] = 0;

	// Right side
	indices[18] = 3; indices[19] = 2; indices[20] = 6;
	indices[21] = 3; indices[22] = 6; indices[23] = 7;

	// Top side
	indices[24] = 1; indices[25] = 5; indices[26] = 6;
	indices[27] = 1; indices[28] = 6; indices[29] = 2;

	// Bottom side
	indices[30] = 4; indices[31] = 0; indices[32] = 3;
	indices[33] = 4; indices[34] = 3; indices[35] = 7;

	IB->Unlock();

	// Position and aim the camera
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);

	m_d3ddev->SetTransform(D3DTS_VIEW, &V);

	// Set projection matrix
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, (float)800 / (float)600, 1.0f, 1000.0f);
	m_d3ddev->SetTransform(D3DTS_PROJECTION, &proj);

	// Set the render states
	m_d3ddev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	std::cout << "Renderer D3D started\n";
}

D3D::~D3D()
{
	// Release
	if (m_d3ddev != NULL)
		m_d3ddev->Release();
	if (m_d3d != NULL)
		m_d3d->Release();
	if (m_d3dspt != NULL)
		m_d3dspt->Release();
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
		m_d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	// Start the scene
	m_d3ddev->BeginScene();

	// Start the sprite render
	//if (m_d3dspt != NULL)
	//	m_d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
}

/*
	Rendering goes here between
*/

void D3D::EndScene()
{
	// End the sprite render
	//if (m_d3dspt != NULL)
	//	m_d3dspt->End();

	D3DXMATRIX Rx, Ry;

	// Rotate 45 degrees on x-axis
	static float x = 0.0f;
	D3DXMatrixRotationX(&Rx, x);
	x += 0.005f;
	if (x >= 6.28f)
		x = 0.0;

	// Increment y-rotation angle each frame
	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);
	y += 0.005f;
	if (y >= 6.28f)
		y = 0.0;

	// Combine rotations
	D3DXMATRIX p = Rx * Ry;

	m_d3ddev->SetTransform(D3DTS_WORLD, &p);

	m_d3ddev->SetStreamSource(0, VB, 0, sizeof(Vertex));
	m_d3ddev->SetIndices(IB);
	m_d3ddev->SetFVF(Vertex::FVF);
	m_d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

	// End drawing the scene
	m_d3ddev->EndScene();
}

void D3D::Render()
{
	// Render the scene
	m_d3ddev->Present(NULL, NULL, NULL, NULL);
}

}