include(src/platform/${PLATFORM_FOLDER}/CMakeLists.txt)
set(PLATFORM_HEADER
	src/platform/init.h
	src/platform/internal.h
	src/platform/window.h
)
set(PLATFORM_SRC
	src/platform/init.cpp
	src/platform/window.cpp
)
list(APPEND PLATFORM_HEADER ${WINDOWS_PLATFORM_HEADER})
list(APPEND PLATFORM_SRC ${WINDOWS_PLATFORM_SRC})