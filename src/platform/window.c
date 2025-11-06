#include "window.h"
#include "win32/w_window.h"
#include "win32/w_context.h"

onWindowCloseFun setCallbackOnWindowClose(window* handle, onWindowCloseFun callback)
{
	void(*prev)(window*) = handle->callbacks.onWindowClose;
	handle->callbacks.onWindowClose = callback;
	return prev;
}

int createWClass()
{
	createWin32WClass();
	return 0;
}

window* createWindow(const wchar_t* title, uint32_t width, uint32_t height)
{
	window* wnd = NULL;
	wnd = malloc(sizeof(window));
	memset(wnd, 0, sizeof(*wnd));
	wnd->height = height;
	wnd->width = width;

	uint64_t title_size = wcslen(title);
	wnd->title = malloc(sizeof(wchar_t) * (title_size + 1));

	wcscpy(wnd->title, title);

	createWin32Window(wnd);
	if (wnd->platformHandle != NULL) {}
	return wnd;
}

void pollEvents()
{
	pollEventsWin32();
}

void destroyWindow(window* handle)
{
	if (handle != NULL) {
		if (handle->platformHandle != NULL) {
			destroyWindowWin32((win32Window*)handle->platformHandle);
			free(handle->platformHandle);
		}
		memset(&handle->callbacks, 0, sizeof(handle->callbacks));
		free(handle);
	}
}

void windowCloseRequest(window* handle)
{
	handle->flags = shouldClose;
	if (handle->callbacks.onWindowClose)
		handle->callbacks.onWindowClose(handle);
}
