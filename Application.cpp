#include "Application.h"

Application::Application(std::string title, int width, int height)
{
	// Remember that we're running
	m_IsOpen = true;
}

Application::~Application()
{
	Close();
}

void Application::Close()
{
	
}

void Application::MakeWindow(LPCSTR title, HINSTANCE hInstance)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "WindowClass1";

	RegisterClassEx(&wc);

    m_hWnd = CreateWindowEx(NULL,
                          "WindowClass1",    // name of the window class
                          "Our First Windowed Program",   // title of the window
                          WS_OVERLAPPEDWINDOW,    // window style
                          300,    // x-position of the window
                          300,    // y-position of the window
                          500,    // width of the window
                          400,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL

    ShowWindow(m_hWnd, SW_SHOWNORMAL);
}

LRESULT CALLBACK Application::WindowProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch(Msg)
    {
        case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            } break;
    }

    return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int Application::ProcessEvents()
{
	return 0;
}

bool operator!(const Application &App)
{
	return !App.m_IsOpen;
}