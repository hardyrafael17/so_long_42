#include "../so_long.h"

void			ft_finish_game(t_program *param)
{
	char 	*moves;
	int		w;
	void *mlx;
	void *win;
	void *erase;

	mlx = param->mlx;
	win = param->window.reference;
	erase = param->image.erase.reference;
	w = ft_create_trgb(0, 255, 255, 255);
	moves = ft_itoa((int) param->record.move_count);
	mlx_put_image_to_window(mlx, win, erase, 0, 0);
	mlx_string_put(mlx, win, 2, 12, w, "Game Over!");
	if(param->map.width > 6)
	{
		mlx_put_image_to_window(mlx, win, erase, 0, 15);
		mlx_string_put(mlx, win, 2, 26, w, "Movimientos: ");
		mlx_string_put(mlx, win, 88, 26, w, moves);
		mlx_put_image_to_window(mlx, win, erase, 0, 30);
		mlx_string_put(mlx, win, 2, 40, w, "Press \"Esc\" key to exit!");
	}
	free(moves);
	param->record.game_over = 1;
}
