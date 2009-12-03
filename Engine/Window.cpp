#include "Window.h"
#include <iostream>

using namespace Engine;

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

Window::Window(WindowParams* wp)
{
	//hInstance = NULL;
	//nCmdShow = SW_SHOWNORMAL;
	
	MakeWindow(wp);
}

Window::Window(std::string title, int width, int height, bool fullscreen)
{
	WindowParams wp;
	wp.title = title;
	wp.width = width;
	wp.height = height;
	wp.fullscreen = fullscreen;

	MakeWindow(&wp);
}

void Window::MakeWindow(WindowParams* wp)
{
	// Fix the WindowParams
	// HACK: This should be done somewhere else
	if (!wp->nCmdShow)
		wp->nCmdShow = SW_SHOWNORMAL;
	if (!wp->x)
		wp->x = 0;
	if (!wp->y)
		wp->y = 0;

    // the handle for the window, filled by a function
    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
	wc.hInstance = wp->hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "WindowClass1";

    // register the window class
    RegisterClassEx(&wc);

    // create the window and use the result as the handle
	DWORD style = WS_OVERLAPPEDWINDOW;
	if (wp->fullscreen)
		style = WS_EX_TOPMOST | WS_POPUP;
    hWnd = CreateWindowEx(NULL,
                          "WindowClass1",    // name of the window class
						  wp->title.c_str(),   // title of the window
                          style,    // window style
						  wp->x,    // x-position of the window
						  wp->y,    // y-position of the window
                          wp->width,    // width of the window
                          wp->height,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          wp->hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL

    // display the window on the screen
	ShowWindow(hWnd, wp->nCmdShow);
}

BOOL Window::ProcessQueue()
{
	MSG msg;

    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return NULL;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	return true;
}