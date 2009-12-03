#include "Engine/Vector.h"
#include "Engine/Window.h"
#include "System/Time.h"
#include "Render/D3D/D3D.h"
#include <iostream>
#include <windows.h>

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	Engine::WindowParams wp;
	wp.title = "Daydream Engine";
	wp.width = 800;
	wp.height = 600;
	wp.fullscreen = false;
	Engine::Window* Window = new Engine::Window(&wp);

	// Direct3D
	Render::D3D* D3D = new Render::D3D(Window->hWnd, &wp);

	LPD3DXFONT font_1;    // create a font object

	D3DXCreateFont(D3D->m_d3ddev,    // the Direct3D Device
				   20, 0,    // font size twenty with the default width
				   FW_BOLD,    // normal font weight
				   1,    // no mipmap levels
				   FALSE,    // not italic
				   DEFAULT_CHARSET,    // default character set
				   OUT_DEFAULT_PRECIS,    // default precision
				   DEFAULT_QUALITY,    // default quality
				   DEFAULT_PITCH || FF_DONTCARE,    // more defaults...
				   "Lucida Console",    // typeface "Arial"
				   &font_1);    // address of the font object created above

	int i = 0;

	while (Window->ProcessQueue())
	{
		D3D->BeginScene();

		    // create a RECT to contain the text
			static RECT textbox; 
			SetRect(&textbox, 0, 0, 640, 480); 
	font_1->
			// draw the Hello World text
			font_1->DrawTextA(NULL,
							  "The Matrix has you...",
							  i,
							  &textbox,
							  NULL,
							  D3DCOLOR_ARGB(255, 0, 255, 0));

		D3D->EndScene();

		D3D->Render();

		if (i < 22)
			i++;

		Sleep(50);
	}

	return 0;
}