#pragma once
#ifndef W_CONTEXT_H
#define W_CONTEXT_H

#include "w_core.h"
#include "platform/window.h"
typedef struct win32Window win32Window;

void setPixelFormatWin32(win32Window* handle);
void setContextWin32(win32Window* handle);


#endif
