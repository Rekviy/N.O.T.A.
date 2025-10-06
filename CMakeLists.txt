cmake_minimum_required(VERSION 3.19)

set(APP_NAME N.O.T.A.)

project(${APP_NAME})

set(NOTA_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${NOTA_ROOT_PATH}/cmake")
include(ConfigDefine)

include("src/platform/CMakeLists.txt")

set(SRC src/entry.cpp
    ${PLATFORM_SRC}
)
set(HEADER src/entry.h src/core.h
    ${PLATFORM_HEADER}
)

list(APPEND SRC ${HEADER})

add_executable(${APP_NAME} ${SRC})

add_subdirectory(external ${PROJECT_BINARY_DIR}/external)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(${APP_NAME} PROPERTIES
                    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                    FOLDER "Internal"
)
#target_compile_definitions(${APP_NAME} PUBLIC )

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
if (WINDOWS)
    set(SUBSYSTEM_LINKER_OPTIONS /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup)
else()
    set(SUBSYSTEM_LINKER_OPTIONS -mwindows)
endif()

target_link_options(${APP_NAME} PRIVATE ${SUBSYSTEM_LINKER_OPTIONS})

target_precompile_headers(${APP_NAME} PRIVATE src/pch.h)