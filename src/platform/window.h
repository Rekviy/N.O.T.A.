#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#include <limits.h>
#include <stdint.h>

#include <math.h>
#include <stdlib.h>

#include <string.h>
#include <wchar.h>

typedef struct window window;

#define BIT(x) (1 << x)
enum windowFlags{shouldClose = BIT(7) };

typedef void (*onWindowCloseFun)(window*);

//window handle
struct window {
	//todo add context handle
	uint32_t height;
	uint32_t width;
	uint8_t flags;
	wchar_t* title;
	//change?
	struct {
		onWindowCloseFun onWindowClose;
	} callbacks;
	
	void* platformHandle;
};

onWindowCloseFun setCallbackOnWindowClose(window* handle, onWindowCloseFun callback);

int createWClass();

window* createWindow(const wchar_t* title, uint32_t width, uint32_t height);

void pollEvents();

void swapBuffers(window* handle);

void* getProcName(const char* name);

void setContext(window* handle);

void destroyWindow(window* handle);

void windowCloseRequest(window* handle);

#endif