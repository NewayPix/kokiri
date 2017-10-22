cmake_minimum_required (VERSION 2.6)
project ("Object Renderer")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

option(debug "Builds the renderer in debug mode" off)

#[[if (WIN32)
	message("Windows build...")

	if ((CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG++) AND NOT debug)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -pedantic -std=c++0x")
		set(EXEC_NAME "renderer.exe")
	elseif((CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG++) AND debug)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1 -g -DDEBUG -pedantic -std=c++0x")
		set(EXEC_NAME "renderer_debug.exe")
	endif() 
elseif (UNIX AND NOT APPLE)
	message("Unix build...")

	set(EXEC_NAME "renderer.out")
endif()]]

set(SRC src/vector3.cpp
		src/opengl_renderer.cpp
		src/debug.cpp
		src/main.cpp)

add_executable (renderer ${SRC})


# Link with OpenGL and SDL2

#target_link_libraries(${EXEC_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLU_LIBRARY})


