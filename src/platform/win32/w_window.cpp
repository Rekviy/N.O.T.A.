#include "w_window.h"
#include "platform/internal.h"
#include "w_init.h"

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int createWin32WClass(void)
{
	WNDCLASSEX wc = { wc.cbSize = sizeof(WNDCLASSEXW) };
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

win32Window* createWin32Window(const wchar_t* title, uint32_t width, uint32_t height)
{
	win32Window* windowHandle = nullptr;
	// Create the window.
	HWND nativeHandle = CreateWindowExW(0L,
		L"tempName_01",
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL,
		NULL,
		((win32Internal*)_tempName.platformInternal)->handle,
		NULL
	);

	if (nativeHandle != NULL) {
		windowHandle = new win32Window{ nativeHandle };

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
	}

	return windowHandle;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (uMsg) {
		case WM_PAINT:

			hdc = BeginPaint(hwnd, &ps);

			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

			EndPaint(hwnd, &ps);
			break;

		case WM_CLOSE:
			if (MessageBoxW(hwnd, L"Close application?", L"winapitest", MB_OKCANCEL) ==
				IDOK)
				DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProcW(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}
