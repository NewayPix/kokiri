project('Kokiri Renderer', 'c', 'cpp',
        version: '1.0.0',
        default_options : ['c_std=c11', 'cpp_std=c++14'])

cc = meson.get_compiler('cpp')
host = host_machine.system()

# Array of system dependencies to be used later
sys = []

# Dependencies
if host != 'windows'
        # This section may not work on Mac plataform.
        gl = cc.find_library('GL', required : true)
        glu = cc.find_library('GLU', required : true)
        dl = cc.find_library('dl', required : true)

        sys = [dl, gl, glu]
else
        # Specific configuration for Windows
        gl = cc.find_library('opengl32', required: true)
        glu = cc.find_library('glu32', required: true)

        sys = [gl, glu]
endif

sdl2 = dependency('sdl2', method: 'pkg-config', required: true)
sdl2_ttf = dependency('sdl2_ttf', method: 'pkg-config', required: false)
sdl2_image = dependency('sdl2_image', method: 'pkg-config', required: false)
sdl2_mixer = dependency('sdl2_mixer', method: 'pkg-config', required: false)

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
       'src/utils/object_printer.cpp']

# Header files of the project
lib_header = include_directories('src/')

glad_c = run_command('./src/3rd/glad/glob.sh')
glad = glad_c.stdout().strip().split('\n')

# Adding 3rd libraries to the src list
lib_src += glad

kokiri_lib = shared_library('kokiri',
                            lib_src,
                            include_directories: lib_header,
                            dependencies: [sys, sdl2],
                            install: true)

#
# Test the Kokiri library
#
subdir('test')
