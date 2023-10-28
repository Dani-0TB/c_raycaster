#include <SDL2/SDL.h>

char map[20][25] = 
{
"#########################",
"#     #      #          #",
"#  p  #                 #",
"#     #      #          #",
"### ###      #          #",
"#     #      #          #",
"#            #          #",
"#     #      #          #",
"##################  #####",
"#          #            #",
"e          #            #",
"#   #  #   #            #",
"#          #            #",
"#          ######  ######",
"#          #            #",
"#   #  #   #            #",
"#                       #",
"#          #            #",
"#########################"
};

int TILE_SIZE = 16;
const SDL_Color CLEAR_COLOR = {5, 5, 10, 255};

void clear_screen(SDL_Renderer *renderer, SDL_Color color)
{
  SDL_SetRenderDrawColor(renderer,
                          color.r,
                          color.g,
                          color.b,
                          color.a);
  SDL_RenderClear(renderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_FRect* rect, SDL_Color color)
{
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRectF(renderer, rect);
}

void draw_map(SDL_Renderer* renderer)
{
  float scale = 2;
  int x = TILE_SIZE * scale;
  int y = TILE_SIZE * scale;
  int w = TILE_SIZE * scale - 2;
  int h = TILE_SIZE * scale - 2;
  int offset_x = 1;
  int offset_y = 1;
  SDL_Color tile_color = {255,255,255,255};
  SDL_Color exit_color = {10,200,0,255};
  SDL_Color color;

  for (int row = 0; row < 30; row++){
    for (int tile = 0; tile < 30; tile++){
      SDL_FRect tile_rect = {x*tile+offset_x,y*row+offset_y,w,h};
      switch (map[row][tile])
      {
        case '#':
          draw_rect(renderer, &tile_rect, tile_color);
          break;
        case 'e':
          draw_rect(renderer, &tile_rect, exit_color);
          break;
      }
    }
  }
}

void draw_game(SDL_Renderer* renderer)
{
  clear_screen(renderer, CLEAR_COLOR);
  draw_map(renderer);
}