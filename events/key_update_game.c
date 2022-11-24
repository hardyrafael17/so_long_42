#include "../so_long.h"

enum Action	validate_key(int key)
{
		if (key == LEFT)
				return (left);
		else if (key == DOWN)
				return (down);
		else if (key == UP)
				return (up);
		else if (key == RIGHT)
				return (right);
		else if (key == ESC)
				return quit;
		else
				return ignore_key;
}

void update_game(enum Action action, t_program *game)
{
		update_map(action, game);
}

int	key_update_game(int key, void *param)
{
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
