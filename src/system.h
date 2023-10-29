#include <SDL2/SDL.h>
#include "system.c"

void handle_input(SDL_Event event, Input* controller);
int init(SDL_Window **window, SDL_Renderer **renderer);
void close_game(SDL_Window **window, SDL_Renderer **renderer);