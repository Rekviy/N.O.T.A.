#include "internal.h"
#include "init.h"
#include "win32/w_init.h"

tempNameInternal _tempName = { };

int tempNameInit()
{
	memset(&_tempName, 0, sizeof(_tempName));
	win32_init();
	return 0;
}
