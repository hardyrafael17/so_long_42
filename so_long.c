/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havoc <havoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:36:09 by havoc             #+#    #+#             */
/*   Updated: 2022/08/17 21:58:40 by havoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	game;
    t_map       map;

	{
		printf("Invalid Argument Count\n"); //Error 1 exit(0);
	}
	map = validate_map(argv[1]);
	if (!map.is_valid)
	{
		printf("Invalid Map\n"); //Error 2
		exit(0);
	}
	game.mlx = mlx_init();
	game.window = ft_new_window(game.mlx, 300, 300, "so_long");
	game.sprite = ft_new_sprite(game.mlx, "./assets/pac_open_left.xpm");
	game.sprite_position.x = 3;
	game.sprite_position.y = 10;
	mlx_put_image_to_window(game.mlx, game.window.reference, \
		game.sprite.reference, game.sprite_position.x, game.sprite_position.y);
	mlx_put_image_to_window(game.mlx, game.window.reference, \
		game.sprite.reference, 288, 0);
	mlx_loop(game.mlx);
	return (0);
}
