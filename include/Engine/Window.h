#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <string>

namespace Engine
{
	struct WindowParams
	{
		WindowParams()
		{
			ZeroMemory(this, sizeof(this));

			this->nCmdShow = SW_SHOWNORMAL;
			this->x = 0;
			this->y = 0;
			this->fullscreen = false;
			this->vsync = false;
		}

		std::string title;
		int width;
		int height;
		int x;
		int y;
		bool fullscreen;
		bool vsync;
		int nCmdShow;
		HINSTANCE hInstance;
		WNDPROC* WndProc;
	};

	class Window
	{
	public:
		HWND hWnd;

		Window();

		void MakeWindow(WindowParams* wp);
		bool ProcessQueue();
		bool Window::SetTitle(std::string title);

		Engine::WindowParams WindowParams;
	private:
		HINSTANCE hInstance;
		int nCmdShow;
	};
}

#endif