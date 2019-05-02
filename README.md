# Kokiri

Kokiri is a framework used to build games. It uses the SDL2 layer to construct
windows, renderers and to handle events. It uses OpenGL as the backend with the
mind of supporting other backends in the future as well, although this may be
quite difficult an effort should be put into to support at least Vulkan.

# Building it

We use Meson as our build system, so just install Meson following (this)[https://mesonbuild.com/Getting-meson.html]
instructions. Mind you some dependencies are required before building it
yourself, such as:

* SDL2
* SDL2 image
* SDL2 ttf
* OpenGL
* C++14

## Linux

On linux you can follow the steps below to build it:

1. `meson .`
2. `cd bin`
3. `ninja`
4. `./renderer.out`

## Windows

Here are some caveats: Don't build it with the statically compiled
library from SDL2, use libSDL2.dll.a along side libSDL2.a when
compiling it. I also use **MinGW** and I expect you to do the same in
order to make it work, feel free to use other compiler though (i.e MSVC).

Follow the steps below to build it:

1. `meson`
2. `cd bin`
2. `ninja`
3. `./renderer.exe`

## OSX

Not tested on this platform, yet. I appreciate your assistance on this. :-)
