#include "window.h"
#include "win32/w_window.h"

int createWClass()
{
	createWin32WClass();
	return 0;
}

window* createWindow(const wchar_t* title, uint32_t width, uint32_t height)
{
	window* wnd = nullptr;
	win32Window* platformWindow = createWin32Window(title, width, height);
	if (platformWindow != nullptr) {
		wnd = new window();
		wnd->height = height;
		wnd->width = width;
		wnd->title = std::wstring(title);
		wnd->platformHandle = platformWindow;
	}
	return wnd;
}

void pollEvents()
{
	pollEventsWin32();
}

void destroyWindow(window* wToDestroy)
{
	if (wToDestroy != nullptr) {
		if(wToDestroy->platformHandle != nullptr)
			delete wToDestroy->platformHandle;
		delete wToDestroy;
	}
}
