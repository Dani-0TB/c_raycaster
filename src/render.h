#ifndef RENDER_H
#define RENDER_H

void clear_screen(SDL_Renderer *renderer, SDL_Color color);
void draw_rect(SDL_Renderer *renderer, SDL_FRect *rect, SDL_Color color);
void draw_map(SDL_Renderer* renderer);
void draw_game(SDL_Renderer *renderer);

#endif