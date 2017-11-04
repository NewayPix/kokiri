# An object renderer

An experimental renderer which uses SDL2 and OpenGL to render `.obj`
files. It is in early stages of development, so don't expect much of it. 

*This was just used in a Computer Graphics presentation. The images
below demonstrate what can be visualized.*

![Cube](cube.png)

# Building it

It is simple, download the source code and use CMake to generate the
proper makefiles. Mind you some dependencies are required before
building it yourself, such as:

* SDL2
* OpenGL

## Linux

Follow the steps below to build it:

1. `cmake ./`
2. `make`
3. `cd bin`
4. `./renderer.out`

## Windows

Here are some caveats: Don't build it with the statically compiled
library from SDL2, use libSDL2.dll.a along side libSDL2.a when
compiling it. I also use **MinGW** and I expect you to do the same in
order to make it work, feel free to use other compiler though (i.e MSVC).

Follow the steps below to build it:

1. `cmake -G "Unix Makefiles" ./ -DCMAKE_PREFIX_PATH=<path_for_sdl2>`
2. `make`
2. `cd bin`
3. `./renderer.exe`

## OSX

Not tested on this platform, yet. I appreciate your assistance on this. :-)

