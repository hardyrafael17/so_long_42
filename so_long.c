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
#include "mlx/mlx.h"

t_program	game;

int	main(int argc, char *argv[])
{
//	t_image image_test;
	if (argc != 2)
	{
		printf("Invalid Argument Count\n"); //Error 1 exit(0);
		return (1);
	}
	game.map = validate_map(argv[1]);
	if (!game.map.is_valid)
	{
		printf("Invalid Map\n"); //Error 2
		exit(0);
	}
	game.mlx = mlx_init();
	game.window = ft_new_window(game.mlx, (game.map.width * 32), (game.map.height * 32), "so_long");
	if (set_images(&game))
		return (1);

	if (ft_put_images_to_map(&game))
		return(1);

	mlx_loop(game.mlx);
	return (0);
}
