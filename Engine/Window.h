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
		}

		std::string title;
		int width;
		int height;
		int x;
		int y;
		bool fullscreen;
		int nCmdShow;
		HINSTANCE hInstance;
	};

	class Window
	{
	public:
		HWND hWnd;

		Window(WindowParams* wp);
		Window(std::string title, int width, int height, bool fullscreen);

		void MakeWindow(WindowParams* wp);
		BOOL ProcessQueue();
	private:
		HINSTANCE hInstance;
		int nCmdShow;
	};
}

#endif