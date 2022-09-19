#include "mlx/mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdio.h>

t_image ft_new_image(void* mlx, int width, int height)
{
	t_image img;
	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;
	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}

void 	*ft_get_sprite(t_program *game, char type)
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

int	ft_put_images_to_map(t_program *game)
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
		width = (int) ((index % game->map.width) * 32);
		height = (int) line * 32;
		if(str[index] == '\n')
		{
			line++;
			index++;
			continue;
		}
		mlx_put_image_to_window(game->mlx, game->window.reference, game->image.background.reference, width, height);
		mlx_put_image_to_window(game->mlx, game->window.reference, ft_get_sprite(game, str[index]) ,width, height);
		index++;
	}

	return (0);
}
