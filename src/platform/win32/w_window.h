#pragma once
#ifndef W_WINDOW_H
#define W_WINDOW_H
//temp
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include "w_core.h"
typedef struct window window;
typedef struct win32Window win32Window;

struct win32Window {
	HWND handle;
	uint32_t height;
	uint32_t width;
	wchar_t* title;
};

int createWin32WClass(void);
void createWin32Window(window* handle);
int pollEventsWin32();
void swapBuffersWin32(win32Window* handle);
void* getProcNameWin32(const char* name);

void destroyWindowWin32(win32Window* window);
#endif 