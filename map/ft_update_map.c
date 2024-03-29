/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:06:55 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:09:06 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_print_stats(t_program *param)
{
	int		y;
	char	*item;
	char	*moves;
	int		w;
	void	*erase;

	erase = param->image.erase.reference;
	w = ft_create_trgb(0, 255, 255, 255);
	moves = ft_itoa((int) param->record.move_count);
	item = ft_itoa(param->record.collectables);
	y = (param->map.height * 32) + 11;
	mlx_put_image_to_window(param->mlx, param->window.reference, erase, 0, y);
	mlx_string_put(param->mlx, param->window.reference, 5, y + 13, w, moves);
	mlx_string_put(param->mlx, param->window.reference, 60, y + 13, w, item);
	free(moves);
	free(item);
}

static void	ft_direction(size_t index, signed int direction, t_program *param)
{
	if (param->map.map_string[index + direction] == '0')
	{
		param->map.map_string[index] = '0';
		param->map.map_string[index + direction] = 'P';
		ft_set_player_position(param, move);
		ft_paint_map(param);
	}
	else if (param->map.map_string[index + direction] == 'C')
	{
		param->map.map_string[index] = '0';
		param->map.map_string[index + direction] = 'P';
		ft_set_player_position(param, increment_all);
		ft_paint_map(param);
	}
	else if (param->map.map_string[index + direction] == 'E' \
		&& param->record.collectables == 0)
	{
		param->record.game_over = 1;
		param->map.map_string[index] = '0';
		param->map.map_string[index + direction] = 'P';
		ft_set_player_position(param, move);
		ft_paint_map(param);
		ft_finish_game(param);
	}
	ft_print_stats(param);
}

void	update_map(enum e_Action action, t_program *param)
{
	t_vector	*current_xy;
	size_t		string_index;

	current_xy = &param->player;
	string_index = (param->player.y * param->map.width) + current_xy->x;
	if (action == right)
		ft_direction(string_index, 1, param);
	if (action == left)
		ft_direction(string_index, -1, param);
	if (action == up)
		ft_direction(string_index, -param->map.width, param);
	if (action == down)
		ft_direction(string_index, param->map.width, param);
}
