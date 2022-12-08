/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:00:11 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:02:51 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

enum e_Action	validate_key(int key)
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
		return (quit);
	else
		return (ignore_key);
}

void	update_game(enum e_Action action, t_program *game)
{
	if(action == quit)
	{
	  free(game->map.map_string);
	  exit(0);
	}
	update_map(action, game);
}

int	key_update_game(int key, void *param)
{
	enum e_Action	action;

	action = validate_key(key);
	if (action == ignore_key)
		return (0);
	update_game(action, param);
	return (0);
}
