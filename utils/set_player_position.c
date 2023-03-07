/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:13:07 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:14:20 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vector	get_coordenates(t_program *game, size_t target)
{
	size_t		x;
	size_t		y;
	t_vector	vector;

	y = (target / game->map.width);
	x = (target % game->map.width);
	vector.x = x;
	vector.y = y;
	return (vector);
}

void	ft_set_player_position(t_program *game, enum e_Record action)
{
	int		count;

	count = 0;
	while (game->map.map_string[count])
	{
		if (game->map.map_string[count] == 'P')
		{
			game->player = get_coordenates(game, count);
			break ;
		}
	count++;
	}
	if (action == move)
		game->record.move_count++;
	else if (action == increment_all)
	{
		game->record.collectables--;
		game->record.move_count++;
	}
}
