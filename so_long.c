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
	t_map		map;
	t_program	mlx;
	t_image		image;

	if (argc != 2)
	{
		printf("Invalid Argument Count\n"); //Error 1
		exit(0);
	}
	map = validate_map(argv[1]);
	if (!map.is_valid)
	{
		printf("Invalid Map\n"); //Error 2
		exit(0);
	}
	mlx_structure.mlx_pointer = mlx_init();
	mlx_structure.window = \
	mlx_new_window(&mlx_structure.mlx_pointer, 960, 800, "So Long");
	mlx_new_image(&mlx_structure.mlx_pointer, 900, 750);
	image = ft_new_sprite(&mlx_structure, "./assets/pac_open_left.xpm");
	mlx_put_image_to_window \
	(&mlx_structure, &mlx_structure.window, &image.pointer, 0, 0);
	return (0);
}
