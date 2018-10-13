cmake_minimum_required (VERSION 2.8)
project ("Object Renderer")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Compile options
option(DEBUG "Builds the renderer in debug mode" off)

# Compile flags
set(CXX_FLAGS "-Wall -O3 -pedantic -std=c++14")
set(CXX_DEBUG_FLAGS "-Wall -O0 -g -DDEBUG -pedantic -std=c++14")

# Build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Call CMake defining the CMAKE_PREFIX_PATH to find the SDL2 include directory
# properly on windows.
# Something like -DCMAKE_PREFIX_PATH=<sdl2_path> where <sdl2_path> may be
# "C:/SDL2/"
find_path(SDL2_INCLUDE_DIR "SDL2/SDL.h")

find_path(GLM_DIR "glm.hpp" PATH_SUFFIXES "glm")

message("Found SDL2: " ${SDL2_INCLUDE_DIR})
message("Found GLM: " ${GLM_DIR})

include_directories("Object Renderer" ${SDL2_INCLUDE_DIR})
include_directories("Object Renderer" ${GLM_DIR})

if (WIN32)
  if (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_DEBUG_FLAGS}")
    set(EXEC_NAME "renderer_debug")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
    set(EXEC_NAME "renderer")
  endif()
elseif (UNIX)
  if (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_DEBUG_FLAGS}")
    set(EXEC_NAME "renderer_debug.out")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
    set(EXEC_NAME "renderer.out")
  endif()
endif()

# TODO: Include all of those projects later

set(SRC src/maths/vector3.cpp
  src/maths/vector3.hpp
  src/graphics/window.hpp
  src/graphics/window.cpp
  src/graphics/primitives.hpp
  src/graphics/primitives.cpp
  src/graphics/renderer.cpp
  src/graphics/renderer.hpp
  src/graphics/shader.hpp
  src/graphics/shader.cpp
  src/utils/object.cpp
  src/utils/object.hpp
  src/utils/loader.hpp
  src/utils/loader.cpp
  src/utils/object_loader.cpp
  src/utils/object_loader.hpp
  src/utils/printer.hpp
  src/utils/printer.cpp
  src/utils/object_printer.hpp
  src/utils/object_printer.cpp
  src/utils/debug/debug.cpp
  src/utils/debug/debug.hpp
  src/main.cpp)

add_executable(${EXEC_NAME} ${SRC})

# Link with OpenGL and SDL2
target_link_libraries(${EXEC_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES}
  ${GLU_LIBRARY})
