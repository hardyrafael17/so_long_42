#include "so_long.h"

int	ft_update_map(int keycode, t_map *map)
{
  if(!map)
	exit (0);
  printf("%d\n", keycode);
  return (0);
}

int	key_input_hook(int keycode, void *param)
{
  ft_update_map(keycode, param);
  // ft_put_images_to_map(param);
  return (0);
}
