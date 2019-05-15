project('Kokiri Renderer', 'c', 'cpp',
        version: '1.0.0',
        default_options : ['c_std=c11', 'cpp_std=c++14'])

cc = meson.get_compiler('cpp')

# For future threads usage of threads uncomment this
#threads = dependency('threads')

gl = cc.find_library('GL', required : true)
glu = cc.find_library('GLU', required : true)
dl = cc.find_library('dl', required : true)
sdl2 = cc.find_library('SDL2', required : true)
sdl2_ttf = cc.find_library('SDL2_ttf', required : true)
sdl2_image = cc.find_library('SDL2_image', required : true)

# Source files of the library
lib_src = ['src/graphics/window.cpp',
       'src/graphics/context.cpp',
       'src/graphics/renderer.cpp',
       'src/graphics/renderer_opengl.cpp',
       'src/graphics/shader.cpp',
       'src/maths/vector3.cpp',
       'src/utils/loader.cpp',
       'src/utils/object.cpp',
       'src/utils/printer.cpp',
       'src/utils/object_loader.cpp',
       'src/utils/object_printer.cpp',
       'src/ui/font.cpp']

# Header files of the project
lib_header = include_directories('src/')

glad_c = run_command('./src/3rd/glad/glob.sh')
glad = glad_c.stdout().strip().split('\n')

# Adding 3rd libraries to the src list
lib_src += glad

kokiri_lib = shared_library('kokiri',
                            lib_src,
                            include_directories: lib_header,
                            dependencies: [dl, sdl2, sdl2_ttf, sdl2_image, glu],
                            install: true)

#
# Test the Kokiri library
#
subdir('test')
