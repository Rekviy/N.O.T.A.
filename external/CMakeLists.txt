cmake_minimum_required(VERSION 3.13)

project(external)

add_subdirectory(glad)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} OpenGL::GL glad)
