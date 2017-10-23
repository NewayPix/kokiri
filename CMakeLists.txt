cmake_minimum_required (VERSION 2.6)
project ("Object Renderer")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SLD2)

# Include SDL2 directory 
include_directories("Object Renderer" ${SDL_INCLUDE_DIR})

# Compile options
option(debug "Builds the renderer in debug mode" off)

# Compile flags 
set(CXX_FLAGS "-Wall -O3 -pedantic -std=c++0x")
set(CXX_DEBUG_FLAGS "-Wall -O1 -g -DDEBUG -pedantic -std=c++0x")

if (WIN32)
	if (debug)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_DEBUG_FLAGS}")
		set(EXEC_NAME "renderer_debug.exe")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
		set(EXEC_NAME "renderer.exe")
	endif()
elseif (UNIX)
	if (debug)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_DEBUG_FLAGS}")
		set(EXEC_NAME "renderer_debug.out")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
		set(EXEC_NAME "renderer.out")
	endif()
endif()

set(SRC src/vector3.cpp
		src/vector3.hpp
		src/opengl_renderer.cpp
		src/opengl_renderer.hpp
		src/debug.cpp
		src/debug.hpp
		src/main.cpp)

add_executable (${EXEC_NAME} ${SRC})


# Link with OpenGL and SDL2
target_link_libraries(${EXEC_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLU_LIBRARY})


