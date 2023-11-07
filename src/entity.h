#ifndef ENTITY_H
#define ENTITY_H

player create_player(float x, float y, float w, float h, float acc, float frict);
void draw_player(SDL_Renderer* renderer,player player);
void update_player(player* player, Input controller, float deltaTime);

#endif