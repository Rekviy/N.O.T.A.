#include "w_init.h"
#include "platform/internal.h"



int win32_init(void)
{
	static win32Internal winInternal;
	winInternal.handle = GetModuleHandleW(NULL);
	_tempName.platformInternal = &winInternal;
	return 0;
}




