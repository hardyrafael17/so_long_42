#include "so_long.h"
int			key_input_hook(int keycode, void *param)
{
  printf("Hello World\nThere's been a key input with %c", keycode);
  if (!param)
	printf("param");
  else
	printf("noParam");
  return (0);
}
