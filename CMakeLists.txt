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

set(SRC src/vector3.cpp
  src/vector3.hpp
  src/renderer.cpp
  src/renderer.hpp
  src/object.cpp
  src/object.hpp
  src/object_loader.cpp
  src/object_loader.hpp
  src/debug.cpp
  src/debug.hpp
  src/main.cpp)

add_executable(${EXEC_NAME} ${SRC})

# Link with OpenGL and SDL2
target_link_libraries(${EXEC_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES}
  ${GLU_LIBRARY})
