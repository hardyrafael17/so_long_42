#include "../so_long.h"

int	initialize_images(t_program *game)
{
	game->image.player = ft_new_sprite(game->mlx, "./assets/img/player1.xpm");
	game->image.enemy = ft_new_sprite(game->mlx, "./assets/img/enemy.xpm");
	game->image.background = ft_new_sprite(game->mlx, "./assets/img/road.xpm");
	game->image.collecatble = ft_new_sprite(game->mlx, "./assets/img/collect1.xpm");
	game->image.exit = ft_new_sprite(game->mlx, "./assets/img/exit.xpm");
	game->image.wall = ft_new_sprite(game->mlx, "./assets/img/wall.xpm");
	return (0);
}
