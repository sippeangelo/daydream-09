#include "Window.h"
#include <iostream>

namespace Engine
{
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch(message)
    {
        // this message is read when the window is closed
        case WM_DESTROY:
            {
                // close the application entirely
                PostQuitMessage(0);
                return 0;
            } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
} 

Window::Window()
{
	//hInstance = NULL;
	//nCmdShow = SW_SHOWNORMAL;
}

void Window::MakeWindow(Engine::WindowParams* wp)
{
	this->WindowParams = *wp;

	// Fix the WindowParams
	// HACK: This should be done somewhere else
	if (!this->WindowParams.nCmdShow)
		this->WindowParams.nCmdShow = SW_SHOWNORMAL;
	if (!this->WindowParams.x)
		this->WindowParams.x = CW_USEDEFAULT;
	if (!this->WindowParams.y)
		this->WindowParams.y = CW_USEDEFAULT;

    // the handle for the window, filled by a function
    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = this->WindowParams.hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "WindowClass1";

    // register the window class
    RegisterClassEx(&wc);

    // create the window and use the result as the handle
	DWORD style = WS_OVERLAPPEDWINDOW;
	//if (this->WindowParams.fullscreen)
	//	style = WS_EX_TOPMOST | WS_POPUP;
    hWnd = CreateWindowEx(NULL,
                          "WindowClass1",    // name of the window class
						  this->WindowParams.title.c_str(),   // title of the window
                          style,    // window style
						  this->WindowParams.x,    // x-position of the window
						  this->WindowParams.y,    // y-position of the window
                          this->WindowParams.width,    // width of the window
                          this->WindowParams.height,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          this->WindowParams.hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL

	// Now resize the window to the right resolution excluding the window borders, if any
	RECT rcClient, rcWindow;
	POINT ptDiff;
	GetClientRect(hWnd, &rcClient);
	GetWindowRect(hWnd, &rcWindow);
	ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;
	ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;
	MoveWindow(hWnd, rcWindow.left, rcWindow.top, this->WindowParams.width + ptDiff.x, this->WindowParams.height + ptDiff.y, TRUE);

    // display the window on the screen
	ShowWindow(hWnd, this->WindowParams.nCmdShow);
}

bool Window::ProcessQueue()
{
	MSG msg;

    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return false;

		//std::cout << msg.message << "\n";

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	return true;
}

bool Window::SetTitle(std::string title)
{
	return SetWindowText(this->hWnd, title.c_str());
}

}