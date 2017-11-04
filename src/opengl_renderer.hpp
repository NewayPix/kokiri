#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __WIN32__
    #include <GL/glext.h>
#endif 

class Renderer {
private:
    SDL_GLContext _gl_context;
public:
    Renderer(SDL_GLContext& gl_context);
    ~Renderer() {};
    
    void render_triangle();
    void render_cube(int size);
    void rotate(float angle, float x, float y, float z);
};

#endif // OPENGL_RENDERER_HPP