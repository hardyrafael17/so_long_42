#include "../so_long.h"
  /*
  a = 97
  s = 115
  d = 100
  w = 119
  esc = 65307
  * */

enum Action	validate_key(int key)
{
		// printf("%d\n", key);
		if (key == 97)
				return (left);
		else if (key == 115)
				return (down);
		else if (key == 119)
				return (up);
		else if (key == 100)
				return (right);
		else if (key == 65307)
				return quit;
		else
				return ignore_key;
}

void update_game(enum Action action, t_program *game)
{
		update_map(action, game);
		//update position
		//repaint
		//enter loop
		printf("Map updated\n");
}

int	key_update_game(int key, void *param)
{
		// printf("%d\n", key);
		//validate key
		enum Action	action;
		
		action = validate_key(key);
		if (action == ignore_key)
		{
				return (0);
		} else if (action == quit)
		{
				exit(0); // TODO free memory
		}
		update_game(action, param);
		//check for errors
		return (0);
}
