# Kokiri

Kokiri is a framework used to build games and simulations. It uses the SDL2 
layer to construct windows, renderers and to handle events. It uses OpenGL as
the backend with the mind of supporting other backends in the future as well, 
although this may be quite difficult an effort should be put into to support 
at least Vulkan.

# Building it

We use premake to generate the build files. This project is built as a static
library so you'll need at least a C++ compiler compatible with the version 17.

Please make sure that the dependencies of this project are satisfied when 
cloning, in other words: clone this project **recursively** (`git clone --recursive`).

Other dependencies such as SDL might arise when compiling the target binary.

## Windows, Linux and possibly OSX

Use premake to generate the appropriate build files, such as Makefiles or 
Visual Studio files. In the following piece of text I describe how I build
the library in a Linux distribution.

```
$ premake gmake2

Building configurations...
Running action 'gmake2'...
Generated Makefile...
Generated kokiri/Makefile...
Done (433ms)

$ # proceed to build using Makefile on Linux
$ make -j 4
```


