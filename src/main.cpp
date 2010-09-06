#include "Engine/Vector.h"
#include "Engine/Color.h"
#include "Engine/Window.h"
#include "System/Timer.h"
#include "System/Thread.h"
#include "Render/D3D9/D3D9.h" // Direct3D 9
#include "Render/D3D10/D3D10.h" // Direct3D 10
#include <iostream>
#include <windows.h>
//#include <d3dx9.h> // HACK: Should not depend on DirectX
#include <string>
#include <sstream>
#include <process.h>
#include <stdio.h>
#include <time.h>

// Error handling
//#define ERROR(message) do { std::cout << "Daydream ERROR> " << message << " <" << __FILE__ << " (" << __LINE__ << ")\n"; } while(false)
#define DDERROR(message) DDError(message, __FILE__, __LINE__);
void DDError(std::string message, char* file, int line)
{
	//std::cout << file << ":" << line << ": " << message << "\n";
	printf("%s:%d:0x%X: %s\n", file, line, 1337, message.c_str());
}
void DDError(int errorcode, char* file, int line)
{
	LPVOID lpMsgBuf;
	if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                errorcode,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                (LPTSTR)&lpMsgBuf,
                0,
                NULL))
	{	
		if (GetLastError() == 317) // The system cannot find message text for message number 0x%1 in the message file for %2.
			printf("%s:%d:0x%X: The system cannot find message text for message number %d (0x%0X)\n", file, line, GetLastError(), errorcode, errorcode);	
		else // Some other unknown error
			printf("%s:%d:0x%X: Format message failed with %d (0x%X)\n", __FILE__, __LINE__, GetLastError(), GetLastError(), GetLastError());	
	}
	else
		printf("%s:%d:0x%X: %s", file, line, errorcode, (char*)lpMsgBuf);

	// Free the buffer.
	LocalFree(lpMsgBuf);
}

// UNDONE: Separate thread handles console I/O
DWORD WINAPI _ConsoleThread(void* Param)
{
	Engine::WindowParams wp;
	wp.title = "Developer Console";
	wp.width = 800;
	wp.height = 200;
	Engine::Window* ConsoleWindow = new Engine::Window();
	ConsoleWindow->MakeWindow(&wp);

	while (ConsoleWindow->ProcessQueue())
	{

	}

	return 0;
}

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	// Make a window
	Engine::WindowParams wp;
	wp.title = "Daydream Engine";
	wp.width = 800;
	wp.height = 600;
	wp.fullscreen = true;
	wp.vsync = true;
	Engine::Window* Window = new Engine::Window();
	Window->MakeWindow(&wp);
	//printf("Original Window: %p\n", Window);

	// Set up a renderer
	Render::IRender* Renderer = new Render::D3D10();
	Renderer->Initialize(Window);


	// Timer
	System::Timer* Timer = new System::Timer(false);
	System::Timer* TimerSmooth = new System::Timer(true);
	//Timer->SmoothFPS(true);

	bool black = true;
	Color col = Color(0, 0, 0);
	int r_a = -1;
	
	while (Window->ProcessQueue())
	//for (int i = 0; i < 5; i++)
	{	
		// Refresh timer
		Timer->Update();
		TimerSmooth->Update();
		//printf("FPS: %f\n", Timer->GetFPS());
		//std::stringstream ss;
		//ss << "FPS: " << TimerSmooth->GetFPS() << " - " << Timer->GetFPS();

		//Renderer->BeginScene();
		//Renderer->EndScene();
		if (col.b == 255)
			r_a = -1;
		else if (col.b == 0)
			r_a = 1;

		col.b += r_a;

		Renderer->Render(col);
	}

	delete Renderer;

	/*
	// Hide the cursor
	//ShowCursor(false);

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
	Text1->SetFont(Font(D3D, "Courier New", 18, Color(0, 0, 0)));
	Text1->SetPos(4, 0);
	*/

	// A sprite
	/*LPD3DXSPRITE d3dspt;    // the pointer to our Direct3D Sprite interface
	D3DXCreateSprite(D3D->m_d3ddev, &d3dspt);    // create the Direct3D Sprite object
	LPDIRECT3DTEXTURE9 sprite;    // the pointer to the sprite
	D3DXCreateTextureFromFile(D3D->m_d3ddev, "sprite.bmp", &sprite);*/
	/*
	Render::D3D::Sprite* Sprite = new Render::D3D::Sprite(D3D);
	Sprite->SetTexture("daydream_blue.bmp");
	Sprite->SetPos(800 / 2, 600 / 2);
	Sprite->SetCenter(512 / 2, 512 / 2);


	//std::stringstream ss;
	//std::ostringstream ss;
	float alpha = 255;

	Timer->Update();
	float NextTick = Timer->Time + 50;

	while (Window->ProcessQueue())
	{
		Timer->Update();
		
		if (Timer->Time >= NextTick)
		{
			if (alpha > 2)
			{
				//std::cout << alpha << std::endl;
				//Sprite->SetColor(Color(255, 255, 255, (int)alpha));
				//alpha = alpha * (0.0001 * delta);
				alpha = (float)(alpha * 0.99);
			}

			NextTick = Timer->Time + 50;
		}

		std::cout << Timer->DeltaTime << std::endl;

		D3D->BeginScene();
			// Render testsprite
			Sprite->Render();

			std::ostringstream ss;
			ss << "FPS: " << Timer->FPS << "\nDelta time (ms): " << Timer->DeltaTime << "\nDelta time (sec): " << Timer->DeltaTime / 1000;
			std::cout << ss.str() << std::endl;
			Text1->SetText(ss.str());
			Text1->Render();
		D3D->EndScene();

		D3D->Render();

		// DEBUG: Sleep for a random ammount of time to test the FPS counter
		//Sleep(rand() % 100 + 1);
	}
	*/

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