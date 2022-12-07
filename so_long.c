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
		ft_handle_error(1);
	g_game.map = validate_map(argv[1]);
	if (!g_game.map.is_valid)
		ft_handle_error(2);
	init_game(&g_game);
	ft_set_player_position(&g_game);
	g_game.mlx = mlx_init();
	g_game.window = ft_new_window(g_game.mlx, (g_game.map.width * 32), \
		(g_game.map.height * 32), "so_long");
	ft_initialize_images(&g_game);
	ft_paint_map(&g_game);
	mlx_key_hook(g_game.window.reference, *key_update_game, &g_game);
	mlx_loop(g_game.mlx);
	return (0);
}
