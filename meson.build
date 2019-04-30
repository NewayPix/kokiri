project('Kokiri Renderer', 'c', 'cpp',
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

src = ['src/main.cpp',
       #'src/3rd/glad/glad.c',
       'src/graphics/window.cpp',
       'src/graphics/renderer.cpp',
       'src/graphics/shader.cpp',
       'src/maths/vector3.cpp',
       'src/utils/loader.cpp',
       'src/utils/object.cpp',
       'src/utils/printer.cpp',
       'src/utils/object_loader.cpp',
       'src/utils/object_printer.cpp',
       'src/ui/font.cpp']

glad_c = run_command('./src/3rd/glad/glob.sh')
glad = glad_c.stdout().strip().split('\n')

# Adding 3rd libraries to the src list
src += glad


libruntime_lt_c=2
libruntime_lt_r=0
libruntime_lt_a=1

lib_version = '@0@.@0@.@0@'.format((libruntime_lt_c - libruntime_lt_a),
                                             libruntime_lt_a,
                                             libruntime_lt_r)

kokiri_lib_shared = shared_library('kokiri',
                                   src,
                                   version : lib_version)

#debug_target = custom_target('Debug',
#                             output : 'renderer_debug.out',
#                             input : sources,
#)

#executable('renderer.out', src,
#           dependencies : [dl, sdl2, sdl2_ttf, sdl2_image, glu])
