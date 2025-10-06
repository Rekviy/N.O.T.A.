#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "w_core.h"

struct win32Internal {
	
	HINSTANCE handle;
};

struct libraryPlatform;
int win32_init(void);

#endif
