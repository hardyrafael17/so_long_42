#include "../so_long.h"

t_image ft_new_image(void* mlx, int width, int height)
{
	t_image img;
	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, \
								&img.line_size, &img.endian);
	return (img);
}

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, \
								 &img.line_size, &img.endian);
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

