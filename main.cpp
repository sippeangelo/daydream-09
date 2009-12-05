#include "Engine/Vector.h"
#include "Engine/Window.h"
#include "System/Timer.h"
#include "Render/D3D/D3D.h"
#include "Render/D3D/Text.h"
#include <iostream>
#include <windows.h>
#include <d3dx9.h>
#include <string>
#include <sstream>

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	// Hide the cursor
	ShowCursor(true);

	Engine::WindowParams wp;
	wp.title = "Daydream Engine";
	wp.width = 800;
	wp.height = 600;
	wp.fullscreen = false;
	Engine::Window* Window = new Engine::Window(&wp);

	// Direct3D
	Render::D3D* D3D = new Render::D3D(Window->hWnd, &wp);

	// Timer
	System::Timer* Timer = new System::Timer(0);

	// Some text
	Render::Text* Text1 = new Render::Text(D3D);
	Text1->SetFont("Courier", 20, FW_BOLD, false);
	Text1->SetPos(Text1->GetPos().x, 100);

	while (Window->ProcessQueue())
	{
		Timer->Update();

		int delta = Timer->Delta;
		int FPS = Timer->FPS;

		D3D->BeginScene();
	
			int delta_time = GetTickCount();

			std::stringstream ss;
			ss << "Delta time: " << delta << "\nFPS: " << FPS;
			std::cout << ss.str();
			Text1->SetPos(0, 0);
			Text1->SetText(ss.str());
			Text1->Render();

		D3D->EndScene();

		D3D->Render();

		//Sleep(rand() % 100 + 1);
	}

	return 0;
}