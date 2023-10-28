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
  float friction;
  SDL_FRect p_rect;
  SDL_Color p_color;
} player;

typedef struct Input
{
  bool left;
  bool right;
  bool up;
  bool down;
}Input;

player create_player(float x, float y, float w, float h, float acc, float frict);
void draw_player(SDL_Renderer* renderer,player player);
void update_player(player* player, Input controller, float deltaTime);
void handle_input(SDL_Event event, Input* controller);

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

void handle_input(SDL_Event event, Input* controller)
{
  if (event.type == SDL_KEYDOWN)
  {
    switch (event.key.keysym.sym)
    {
      case SDLK_LEFT:
      {
        controller->left = true;
        break;
      }
      case SDLK_RIGHT:
      {
        controller->right = true;
        break;
      }
      case SDLK_UP:
      {
        controller->up = true;
        break;
      }
      case SDLK_DOWN:
      {
        controller->down = true;
        break;
      }
      default:
        break;
    }
  }
  else if (event.type == SDL_KEYUP)
  {
    switch (event.key.keysym.sym)
    {
      case SDLK_LEFT:
      {
        controller->left = false;
        break;
      }
      case SDLK_RIGHT:
      {
        controller->right = false;
        break;
      }
      case SDLK_UP:
      {
        controller->up = false;
        break;
      }
      case SDLK_DOWN:
      {
        controller->down = false;
        break;
      }
      default:
        break;
    }
  }
}

/********************
 * Initializes a new player type with predefined 
 * variables and returns the player type.
*/
player create_player(float x, float y, float w, float h, float acc, float frict)
{
  player new;
  // Player
  new.pos_x = x;
  new.pos_y = y;
  new.delta_x = 0;
  new.delta_y = 0;
  new.acceleration = acc;
  new.friction = frict;

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

void update_player(player* player, Input controller, float deltaTime)
{
  if (controller.left)
  {
    player->delta_x -= player->acceleration * deltaTime;
  }
  if (controller.right)
  {
    player->delta_x += player->acceleration * deltaTime;
  }
  if (controller.up)
  {
    player->delta_y -= player->acceleration * deltaTime;
  }
  if (controller.down)
  {
    player->delta_y += player->acceleration * deltaTime;
  }

  player->pos_x += player->delta_x;
  player->delta_x *= player->friction;
  player->p_rect.x = player->pos_x;

  player->pos_y += player->delta_y;
  player->delta_y *= player->friction;
  player->p_rect.y = player->pos_y;
}