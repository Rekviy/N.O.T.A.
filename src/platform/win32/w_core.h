#pragma once
#ifndef W_CORE_H
#define W_CORE_H

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#include <limits.h>
#include <stdint.h>

#include <math.h>
#include <stdlib.h>

#include <string.h>
#include <wchar.h>

#include <windows.h>

#endif