#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "w_core.h"

typedef struct {

	HINSTANCE handle;
} win32Internal;

struct libraryPlatform;
int win32_init(void);

#endif
