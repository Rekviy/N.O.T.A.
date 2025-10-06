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

struct win32Window {
	HWND handle;
	uint8_t height;
	uint8_t width;
	wchar_t* title;
};

int createWin32WClass(void);
win32Window* createWin32Window(const wchar_t* title, uint32_t width, uint32_t height);
int pollEventsWin32();
#endif 