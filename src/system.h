#ifndef SYSTEM_H
#define SYSTEM_H

typedef struct Input
{
  bool left;
  bool right;
  bool up;
  bool down;
}Input;

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

void handle_input(SDL_Event event, Input* controller);
int init(SDL_Window **window, SDL_Renderer **renderer);
void close_game(SDL_Window **window, SDL_Renderer **renderer);

#endif