#include "helpers.c"



typedef struct Vector2
{
  int x;
  int y;
} Vector2; 

float get_deltaTime(Uint32 current_step, Uint32 last_step);