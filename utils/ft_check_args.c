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

#include "../so_long.h"

static void	ft_print_usage(void)
{
	ft_write("To start the game please type 'so_long map.ber'\n\n", 1);
	ft_write("To move, use the keys 'a', 's', 'd', 'w', left, ", 1);
	ft_write("down, right and ", 1);
	ft_write("up respectively,", 1);
	ft_write("\n use the 'Esc' to exit the game without confirm", 1);
	ft_write("ation.\n\n The objective is to collect all the gifts,", 1);
	ft_write(" then exit the game with the girl\n\n", 1);
	ft_write("Enjoy!!!!\n\n", 1);
	exit(0);
}

void	ft_check_args(int argc, char *argv[])
{
	int	length;

	if (argc != 2)
	{
		ft_write("One argument needed, a valid *.ber map\n", 2);
		exit(1);
	}
	length = ft_strlen(argv[1]);
	if (!ft_strncmp(argv[1], "-h", 3) || !(ft_strncmp(argv[1], "--help", 7)))
	{
		ft_print_usage();
		exit(0);
	}
	else if ((length > 4 && ft_strncmp(argv[1] + length - 4, ".ber", 5)) || \
	length < 4)
	{
		ft_write("Map name must be in the format of '*.ber'!\n", 2);
		exit(1);
	}
}
