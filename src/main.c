#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "system.h"
#include "render.h"
#include "helpers.h"

typedef struct player_struct
{
  float pos_x;
  float pos_y;
  float delta_x;
  float delta_y;
  float acceleration;
  SDL_FRect p_rect;
  SDL_Color p_color;
} player;

player create_player(float x, float y, float w, float h, float acc);
void draw_player(SDL_Renderer* renderer,player player);

int main(int argc, char *argv[])
{
  SDL_Window *gWindow = NULL;
  SDL_Renderer *renderer = NULL;

  if (!init(&gWindow, &renderer))
  {
    return -1;
  }

  player p1 = create_player(100,70,10,10,100); 
  
  float deltaTime = 0;
  Uint32 last_step = SDL_GetTicks();
  
  SDL_Event game_event;
  
  bool game = true;
  
  while (game)
  {
    // Game Loop
    Uint32 current_step = SDL_GetTicks();
    if (last_step < current_step)
    {
      deltaTime = get_deltaTime(current_step, last_step);
      // Game Event Loop
      while(SDL_PollEvent(&game_event))
      {
        if (game_event.type == SDL_QUIT){
          game = false;
        }
        else if (game_event.type == SDL_KEYDOWN)
        {
          if (game_event.key.keysym.sym == SDLK_LEFT)
          {
              p1.delta_x -= p1.acceleration * deltaTime;
          }
          if (game_event.key.keysym.sym == SDLK_RIGHT)
          {
              p1.delta_x += p1.acceleration * deltaTime;
          }
          if (game_event.key.keysym.sym == SDLK_UP)
          {
              p1.delta_y -= p1.acceleration * deltaTime;
          }
          if (game_event.key.keysym.sym == SDLK_DOWN)
          {
              p1.delta_y += p1.acceleration * deltaTime;
          }
        }
      }
      // Update
      float friction = 0.99;
      p1.pos_x += p1.delta_x;
      p1.pos_y += p1.delta_y;
      p1.delta_x *= friction;
      p1.delta_y *= friction;
      
      p1.p_rect.x = p1.pos_x;
      p1.p_rect.y = p1.pos_y;
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

/********************
 * Initializes a new player type with predefined 
 * variables and returns the player type.
*/
player create_player(float x, float y, float w, float h, float acc)
{
  player new;
  // Player
  new.pos_x = x;
  new.pos_y = y;
  new.delta_x = 0;
  new.delta_y = 0;
  new.acceleration = acc;

  // Rect
  new.p_rect.x = new.pos_x;
  new.p_rect.y = new.pos_y;
  new.p_rect.w = w;
  new.p_rect.h = w;

  //Color
  new.p_color.r = 255;
  new.p_color.g = 0;
  new.p_color.b = 0;
  new.p_color.a = 255;

  return new;
}

void draw_player(SDL_Renderer* renderer, player player)
{
  draw_rect(renderer, &player.p_rect, player.p_color);
}

void update_player(player player)
{

}