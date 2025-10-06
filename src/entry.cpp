#include "core.h"
#include "entry.h"
#include <glad/glad.h>

int main(int argc, char** argv)
{
	tempNameInit();
	createWClass();
	window* handle = createWindow(L"something",1080,720);
	
	//set callbacks
	bool running = true;
	while (running) {
		pollEvents();
	}
}
