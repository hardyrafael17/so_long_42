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
	int		row;
	char	*joined;
	char	*string_hold;
	char	*holder;

	if(!fd)
		return (0);
	
	i = 0;
	string = get_next_line(fd);
	map_width = ft_strlen(string);
	row = 1;
	joined = string;
	while(string)
	{
			holder = string;
			string = get_next_line(fd);	
			if(!string)
			{
					if(ft_strlen(holder) != map_width -1)
					{
							printf("wrong width");
							exit (0);
					}						
					while(holder[i])
					{
							if(holder[i] != '1')
							{
									printf("%s\n", holder);
									printf("wrong edge bottom, >>>%d<<<\n", holder[i]);
									exit(0);
							}
							i++;
					}
			} else {
					if(ft_strlen(holder) != map_width)
							printf("wrong width....");
			}
		if(string)
		{
				holder = joined;
				joined = ft_strjoin(joined, string);
				free(holder);
				++row;	
		}
	}
	printf("length -> %d, rows-> %d\n map -> \n%s", ft_strlen(joined), row, joined);
	exit (0);
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
