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
src += glad

kokiri_lib = shared_library('kokiri',
                            lib_src,
                            include_directories: lib_header,
                            dependencies: [dl, sdl2, sdl2_ttf, sdl2_image, glu]
                            install: true)

<<<<<<< HEAD
libruntime_lt_c=2
libruntime_lt_r=0
libruntime_lt_a=1

lib_version = '@0@.@0@.@0@'.format((libruntime_lt_c - libruntime_lt_a),
                                             libruntime_lt_a,
                                             libruntime_lt_r)

kokiri_lib_shared = shared_library('kokiri',
                                   src,
                                   version : lib_version)
=======


#
# Test the Kokiri library
#
>>>>>>> 3efec79 (Add the library and the test targets)

test_src = ['test/main.cpp']

<<<<<<< HEAD
#executable('renderer.out', src,
#           dependencies : [dl, sdl2, sdl2_ttf, sdl2_image, glu])
=======
executable('renderer_test',
           test_src,
           link_with: kokiri_lib,
           include_directories: lib_header,
           dependencies : [dl, sdl2, sdl2_ttf, sdl2_image, glu])
>>>>>>> 3efec79 (Add the library and the test targets)
