#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <SDL2/SDL.h>

#ifdef __linux__
	#include <GL/gl.h>
	#include <GL/glu.h>
#elif __windows__
	#include <gl.h>
	#include <glu.h>
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