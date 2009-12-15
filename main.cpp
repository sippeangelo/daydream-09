#include "Engine/Vector.h"
#include "Engine/Color.h"
#include "Engine/Window.h"
#include "System/Timer.h"
#include "System/Thread.h"
#include "Render/D3D.h"
#include <iostream>
#include <windows.h>
#include <d3dx9.h>
#include <string>
#include <sstream>
#include <process.h>
#include <time.h>

DWORD WINAPI _ConsoleThread(void* Param)
{
	Engine::WindowParams wp;
	wp.title = "Developer Console";
	wp.width = 800;
	wp.height = 200;
	Engine::Window* ConsoleWindow = new Engine::Window(&wp);

	while (ConsoleWindow->ProcessQueue())
	{

	}

	return 0;
}

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	Color col(50, 50, 50);


	// Hide the cursor
	ShowCursor(true);

	// Start the console thread
	System::Thread* Thread = new System::Thread(&_ConsoleThread);
	//Thread->Start();

	Engine::WindowParams wp;
	wp.title = "Daydream Engine";
	wp.width = 800;
	wp.height = 600;
	wp.fullscreen = false;
	wp.vsync = false;
	Engine::Window* Window = new Engine::Window(&wp);

	// Direct3D
	Render::D3D::Interface* D3D = new Render::D3D::Interface(Window->hWnd, &wp);

	// Timer
	System::Timer* Timer = new System::Timer(0);

	// Some text
	Render::D3D::Text* Text1 = new Render::D3D::Text(D3D);
	Text1->SetFont("Courier New", 18, NULL, false);
	Text1->SetPos(4, 0);

	// A sprite
	/*LPD3DXSPRITE d3dspt;    // the pointer to our Direct3D Sprite interface
	D3DXCreateSprite(D3D->m_d3ddev, &d3dspt);    // create the Direct3D Sprite object
	LPDIRECT3DTEXTURE9 sprite;    // the pointer to the sprite
	D3DXCreateTextureFromFile(D3D->m_d3ddev, "sprite.bmp", &sprite);*/
	Render::D3D::Sprite* Sprite = new Render::D3D::Sprite(D3D);
	Sprite->SetTexture("daydream_blue.bmp");
	Sprite->SetPos(800 / 2, 600 / 2);
	Sprite->SetCenter(512 / 2, 512 / 2);


	//std::stringstream ss;
	//std::ostringstream ss;
	float alpha = 255;

	while (Window->ProcessQueue())
	{
		Timer->Update();

		int delta = Timer->Delta / 1000;
		int FPS = (int)Timer->FPS;

		D3D->BeginScene();
			std::ostringstream ss;
			ss << "Delta time: " << Timer->Delta / 1000;
			std::cout << ss.str() << std::endl;
			Text1->SetText(ss.str());
			Text1->Render();

			// Render testsprite
			if (alpha > 0)
			{
				Sprite->SetColor(255, 255, 255, (int)alpha);
				//alpha = alpha * (0.0001 * delta);
				alpha = (float)(alpha * 0.995);
				Sprite->Render();
			}

		D3D->EndScene();

		D3D->Render();

		// DEBUG: Sleep for a random ammount of time to test the FPS counter
		//Sleep(rand() % 100 + 1);
	}

	/*
	LARGE_INTEGER ticksPerSecond;
	LARGE_INTEGER this_tick;

	LARGE_INTEGER last_tick;
	QueryPerformanceCounter(&last_tick);

	// get the high resolution counter's accuracy
	QueryPerformanceFrequency(&ticksPerSecond);

	while (true)
	{
		QueryPerformanceCounter(&this_tick);
		float ewelew = (this_tick.QuadPart - last_tick.QuadPart);
		std::cout << ewelew << "\n";
		last_tick = this_tick;
	}
	*/

	return 0;
}