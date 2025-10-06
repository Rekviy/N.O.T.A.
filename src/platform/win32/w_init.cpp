#include "w_init.h"
#include "platform/internal.h"



int win32_init(void)
{
	static win32Internal winInternal;
	winInternal.handle = GetModuleHandleW(NULL);
	_tempName.platformInternal = &winInternal;
	return 0;
}


int pollEventsWin32()
{
	MSG msg = {};
	
	while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;
}



