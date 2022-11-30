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

t_program	g_game;

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid Argument Count\n");
		return (1);
	}
	g_game.map = validate_map(argv[1]);
	if (!g_game.map.is_valid)
	{
		printf("Invalid Map\n");
		exit(0);
	}
	init_game(&g_game);
	set_player_position(&g_game);
	g_game.mlx = mlx_init();
	g_game.window = ft_new_window(g_game.mlx, (g_game.map.width * 32), \
		(g_game.map.height * 32), "so_long");
	if (initialize_images(&g_game))
		return (1);
	if (paint_map(&g_game))
		return (1);
	mlx_key_hook(g_game.window.reference, *key_update_game, &g_game);
	mlx_loop(g_game.mlx);
	return (0);
}
