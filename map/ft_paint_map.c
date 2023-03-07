/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:03:57 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:05:59 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_stats_header_string(t_program *game)
{
	int		y;
	int		w;
	void	*mlx;
	void	*win;

	if (game->record.stats_header_printed)
		return ;
	mlx = game->mlx;
	win = game->window.reference;
	w = ft_create_trgb(0, 255, 255, 255);
	y = (game->map.height * 32) + 11;
	mlx_string_put(mlx, win, 1, y, w, "Moves |");
	mlx_string_put(mlx, win, 55, y, w, "Items Left");
	game->record.stats_header_printed++;
}

void	*ft_get_sprite(t_program *game, char type)
{
	if (type == '0')
		return (game->image.background.reference);
	else if (type == '1')
		return (game->image.wall.reference);
	else if (type == 'C')
		return (game->image.collecatble.reference);
	else if (type == 'E')
		return (game->image.exit.reference);
	else if (type == 'P')
		return (game->image.player.reference);
	else
		return (game->image.background.reference);
}

void	ft_paint_map(t_program *game)
{
	size_t	line;
	size_t	index;
	char	*str;
	int		width;
	int		height;

	str = game->map.map_string;
	line = 0;
	index = 0;
	while (str[index])
	{
		width = (int)((index % game->map.width) * 32);
		height = (int) line * 32;
		if (str[index] == '\n')
		{
			line++;
			index++;
			continue ;
		}
		mlx_put_image_to_window(game->mlx, game->window.reference, \
			game->image.background.reference, width, height);
		mlx_put_image_to_window(game->mlx, game->window.reference, \
			ft_get_sprite(game, str[index++]), width, height);
	}
	ft_stats_header_string(game);
}
