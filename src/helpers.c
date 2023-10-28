#include <SDL2/SDL.h>

float get_deltaTime(Uint32 current_step, Uint32 last_step)
{
  return (current_step - last_step) * 0.001;
}