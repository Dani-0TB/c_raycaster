#include <SDL2/SDL.h>

const int WIN_WIDTH = 800, WIN_HEIGHT = 600;
char* WIN_TITLE = "Raycaster";
/*
  Initializes SDL subsystems and the main
  screen whith a corresponding rendering
  context. Returns 0 if anything fails.
*/
int init(SDL_Window **window, SDL_Renderer **renderer)
{
  printf("Initializing Video...\n");
  SDL_InitSubSystem(SDL_INIT_VIDEO);
  if (!SDL_WasInit(SDL_INIT_VIDEO))
  {
    printf("SDL video was not initialized. SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  printf("Video was initialized succesfully!\n");

  printf("Creating Window...\n");
  *window = SDL_CreateWindow(
      WIN_TITLE,
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WIN_WIDTH, WIN_HEIGHT,
      0);
  if (!*window)
  {
    printf("SDL window was not created. SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  printf("Window Created succesfully!\n");

  printf("Creating Renderer...\n");
  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if (!*renderer)
  {
    printf("SDL renderer was not created. SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  printf("Renderer Created succesfully!\n");

  return 1;
}

/*
  Executes SDL cleanup functions plus
  some other functions that might be
  required to free allocated memory.
*/
void close_game(SDL_Window **window, SDL_Renderer **renderer)
{
  SDL_DestroyRenderer(*renderer);
  SDL_DestroyWindow(*window);
  SDL_Quit();
}

