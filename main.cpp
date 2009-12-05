#include "Engine/Vector.h"
#include "Engine/Window.h"
#include "System/Time.h"
#include "Render/D3D/D3D.h"
#include "Render/D3D/Text.h"
#include <iostream>
#include <windowss.h>
#include <d3dx9.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main()
{
	// Hide the cursor
	ShowCursor(false);

	Engine::WindowParams wp;
	wp.title = "Daydream Engine";
	wp.width = 800;
	wp.height = 600;
	wp.fullscreen = false;
	Engine::Window* Window = new Engine::Window(&wp);

	// Direct3D
	Render::D3D* D3D = new Render::D3D(Window->hWnd, &wp);

	// Some text
	Render::Text* Text1 = new Render::Text(D3D);
	Text1->SetFont("Courier", 20, FW_BOLD, false);
	Text1->SetText("Wake up, Neo...");

	int i = 1;

	while (Window->ProcessQueue())
	{
		D3D->BeginScene();

			Text1->Render(i);

		D3D->EndScene();

		D3D->Render();

		Sleep(50);
		
		if (i >= Text1->GetText().length())
		{
			i = 1;
			Text1->SetText("Follow the white rabbit..");
		}
		else
			i++;
	}

	return 0;
}