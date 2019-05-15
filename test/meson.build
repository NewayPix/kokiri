window_src = ['test_window.cpp']

executable('window_test',
           window_src,
           link_with: kokiri_lib,
           include_directories: lib_header,
           dependencies : [dl, sdl2, sdl2_ttf, sdl2_image, glu])
