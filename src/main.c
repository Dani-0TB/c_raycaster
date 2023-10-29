#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "helpers.h"
#include "system.h"
#include "render.h"
#include "entity.h"

int main(int argc, char *argv[])
{
  SDL_Window *gWindow = NULL;
  SDL_Renderer *renderer = NULL;
  
  Input controller = {0,0,0,0};

  if (!init(&gWindow, &renderer))
  {
    return -1;
  }

  player p1 = create_player(100,70,10,10,10,0.9); 
  
  float deltaTime = 0;
  Uint32 last_step = SDL_GetTicks();
  
  SDL_Event game_event;
  
  bool game = true;
  while (game)
  {
    // Game Loop
    Uint32 current_step = SDL_GetTicks();
    bool key_pressed = false;
    if (last_step < current_step)
    {
      deltaTime = get_deltaTime(current_step, last_step);
      // Game Event Loop
      while(SDL_PollEvent(&game_event))
      {
        switch (game_event.type){
          case SDL_QUIT:
            game = false;
            break;
        }
        handle_input(game_event, &controller);
      }
      //Update
      update_player(&p1, controller, deltaTime);
      // Draw
      draw_game(renderer);
      draw_player(renderer, p1);
      SDL_RenderPresent(renderer);
      last_step = SDL_GetTicks();
    }
  }

  close_game(&gWindow, &renderer);

  return 0;
}