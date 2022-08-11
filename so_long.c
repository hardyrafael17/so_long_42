/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havoc <havoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:36:09 by havoc             #+#    #+#             */
/*   Updated: 2022/08/10 23:36:25 by havoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	validate_map(int fd)
{
	char	*string;
	int		i;
	int		map_width;
	int		map_height;
	int		is_player_present;
	int		are_collectables_present;
	int		row;
	int		bottom_row;
	int		j;
	int		k;

	if(!fd)
		return (0);
	
	i = 0;
	string = get_next_line(fd);
	map_width = ft_strlen(string);
	row = 1;
	while(string)
	{
		bottom_row = 0;
		if(map_width != ft_strlen(string))
			return (0);
		while(string[i])
		{
			if(string[i] == 'P')
				is_player_present++;
			if(string[i] == 'C')
				are_collectables_present++;
			if((string[i] != '1' && row == 1) || (row != 1 && string[0] != 1) || ( row != 1 && string[map_width - 1] != 1))
				return (0);
			++i;
		}
		j = 0;
		k = 0;
		while(string[j])
		{
			if(string[j] == '1')
				++k;
			if(k == map_width)	
				bottom_row = 1;
			++j;
		}
		printf("%s", string);
		free(string);
		string = get_next_line(fd);	
		++row;
	}
	if( bottom_row != 1 || is_player_present != 1 || are_collectables_present < 1)
		   return (0);	

	exit(0);	

}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		is_map_valid;
	FILE	*map;
	int		fd;
	
	fd = open("map.ber", O_RDONLY);

	is_map_valid = validate_map(fd);
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 600, "Singleton");
	img.img = mlx_new_image(mlx, 920, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
