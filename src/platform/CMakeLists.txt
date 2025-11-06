include(src/platform/${PLATFORM_FOLDER}/CMakeLists.txt)
set(PLATFORM_HEADER
	src/platform/init.h
	src/platform/internal.h
	src/platform/window.h
	src/platform/lib.h
)
set(PLATFORM_SRC
	src/platform/init.c
	src/platform/window.c
)
list(APPEND PLATFORM_HEADER ${WINDOWS_PLATFORM_HEADER})
list(APPEND PLATFORM_SRC ${WINDOWS_PLATFORM_SRC})