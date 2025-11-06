#include "w_window.h"
#include "platform/internal.h"
#include "w_init.h"
#include "platform/window.h"

void OnSize(HWND hwnd, UINT flag, int width, int height);
LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int createWin32WClass(void)
{
	WNDCLASSEX wc = { .cbSize = sizeof(WNDCLASSEXW) };
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = ((win32Internal*)_tempName.platformInternal)->handle;//use static_cast???
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"tempName_01";

	RegisterClassExW(&wc);

	return 0;
}

void createWin32Window(window* handle)
{
	win32Window* windowHandle = NULL;
	// Create the window.
	HWND nativeHandle = CreateWindowExW(0L,
		L"tempName_01",
		handle->title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, handle->width, handle->height,
		NULL,
		NULL,
		((win32Internal*)_tempName.platformInternal)->handle,
		NULL
	);

	if (nativeHandle != NULL) {
		windowHandle = malloc(sizeof(win32Window));
		windowHandle->handle = nativeHandle;

		int showCommand = SW_SHOWNA;
		STARTUPINFOW si = { sizeof(si) };
		GetStartupInfoW(&si);
		if (si.dwFlags & STARTF_USESHOWWINDOW)
			showCommand = si.wShowWindow;

		ShowWindow(nativeHandle, showCommand);
		UpdateWindow(nativeHandle);

		BringWindowToTop(nativeHandle);
		SetForegroundWindow(nativeHandle);
		SetFocus(nativeHandle);
		SetPropW(nativeHandle, L"TEST", handle);
	}
	handle->platformHandle = windowHandle;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	window* handle = (window*)GetPropW(hwnd, L"TEST");
	PAINTSTRUCT ps;
	HDC hdc;
	switch (uMsg) {
		/*case WM_SIZE:
				width = LOWORD(lParam);
				height = HIWORD(lParam);
				OnSize(hwnd, (UINT)wParam, width, height);
				break;*/

		case WM_PAINT:

			hdc = BeginPaint(hwnd, &ps);

			//FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

			EndPaint(hwnd, &ps);
			break;

		case WM_CLOSE:
			windowCloseRequest(handle);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProcW(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

void OnSize(HWND hwnd, UINT flag, int width, int height)
{
	// handle resizing
}

int pollEventsWin32()
{
	MSG msg;

	while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;
}

void* getProcNameWin32(const char* name)
{
	return wglGetProcAddress(name);
}

void swapBuffersWin32(win32Window* handle)
{
	HDC hdc = GetDC(handle->handle);
	SwapBuffers(hdc);
}

void destroyWindowWin32(win32Window* window)
{
	HDC hdc = GetDC(window->handle);
	HGLRC hRC = wglGetCurrentContext();
	if (hRC != NULL) {
		wglMakeCurrent(hdc, NULL);
		wglDeleteContext(hRC);
	}
	ReleaseDC(window->handle, hdc);
	DestroyWindow(window->handle);
}
