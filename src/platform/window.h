#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <xutility>
#include <string>
//window handle
struct window {
	//todo add context handle
	uint8_t height;
	uint8_t width;
	std::wstring title;
	void* platformHandle;
};

int createWClass();

window* createWindow(const wchar_t* title, uint32_t width, uint32_t height);

void pollEvents();

void destroyWindow(window* wToDestroy);

#endif