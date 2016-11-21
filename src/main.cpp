#include <iostream>
#include <cstdint>

#include <SDL2/SDL.h>

#include "debug.hpp"
#include "opengl_renderer.hpp"


int main(int argc, char **argv) {

	bool running = true;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;

	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        Debug::log_err("Failed to initialize SDL2 video system");
        return 1;
    }

	window = SDL_CreateWindow("Object Renderer", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		Debug::log_err("Failed to initialize window");
		Debug::log_err("Reason: ", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		Debug::log_err("Failed to initialize renderer");
		Debug::log_err("Reason: ", SDL_GetError());
		return 1;
	}

	SDL_GLContext gl = SDL_GL_CreateContext(window);
	// Send the gl context to the renderer
	Renderer opengl_renderer = Renderer(gl);

	uint32_t frame = 0;

	uint32_t fps = 60;

	Debug::log("OpenGL version: ", glGetString(GL_VERSION));
	Debug::log("OpenGL vendor: ", glGetString(GL_VENDOR));
	Debug::log("OpenGL renderer: ", glGetString(GL_RENDERER));
	Debug::log("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));

	while (running) {
		frame = SDL_GetTicks();

		SDL_PollEvent(&event);

		switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
				/**
				 * This is synchronous state.
				 */
            	switch(event.key.keysym.sym) {
            		case SDLK_x:
            			opengl_renderer.rotate(4, 1, 0, 0);
            			break;
            		case SDLK_y:
            			opengl_renderer.rotate(4, 0, 1, 0);
            			break;
            		case SDLK_z:
            			opengl_renderer.rotate(4, 0, 0, 1);
            			break;
            	}
            default:
                //std::cout << "Event: " << event.type << std::endl;
            	break;
		}
		opengl_renderer.rotate(1, 1, 1, 0);
        opengl_renderer.render_cube(2.0);
        SDL_GL_SwapWindow(window);

		if (1000/fps > (SDL_GetTicks() - frame)) {
			SDL_Delay(1000/fps-(SDL_GetTicks()-frame));
		}
	}

    SDL_GL_DeleteContext(gl);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	return 0;
}
