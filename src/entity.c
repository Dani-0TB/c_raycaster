#include <SDL2/SDL.h>
#include <stdbool.h>
#include "system.h"
#include "render.h"
#include "entity.h"

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

void set_player(player* player)
{

}