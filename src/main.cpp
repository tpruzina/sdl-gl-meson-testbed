#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

SDL_Window *mw;
SDL_GLContext mctx;

auto sdl_init() -> bool
{
        auto ret = SDL_Init(SDL_INIT_VIDEO);
        if(ret < 0)  goto fail_init;

        mw = SDL_CreateWindow(
                "sdl-gl",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                1920/2,
                1080/2,
                SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_RESIZABLE
        );
        if(!mw) goto fail_mw;

        mctx = SDL_GL_CreateContext(mw);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetSwapInterval(1);

        return true;

fail_post_glxcontext:
        SDL_GL_DeleteContext(mctx);
fail_glcontext:
        SDL_DestroyWindow(mw);
fail_mw:
        SDL_Quit();
fail_init:
        return false;
}

auto sdl_cleanup() -> void
{
	// Delete our OpengL context
	SDL_GL_DeleteContext(mctx);

	// Destroy our window
	SDL_DestroyWindow(mw);
	SDL_Quit();
        return;
}

auto fill_color(float r, float g, float b, float a=1.0) -> void
{
        glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(mw);
        return;
}

void sdl_event_loop()
{
	bool should_quit = false;
	while (!should_quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				should_quit = true;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					should_quit = true;
					break;

				case SDLK_r:
					// Cover with red and update
					fill_color(1.0, 0.0, 0.0, 1.0);
					break;

				case SDLK_g:
					// Cover with green and update
					fill_color(0.0, 1.0, 0.0, 1.0);
					break;

				case SDLK_b:
					// Cover with blue and update
					fill_color(0.0, 0.0, 1.0, 1.0);
					break;

				default:
					break;
				}
			}
		}
	}
        return;
}

auto main() -> int
{
        if(!sdl_init())
                return -1;
        
        sdl_event_loop();
        sdl_cleanup();

        return 0;
}
