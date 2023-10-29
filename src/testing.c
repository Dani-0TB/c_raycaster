#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char* text_buffer = malloc(sizeof(char) * 140);

  char temp_text = *text_buffer;

  free(text_buffer);

  text_buffer = malloc(sizeof(temp_text) + sizeof(char) * 140);

  text_buffer = &temp_text;

  free(text_buffer);
}