#include "../so_long.h"

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

int	paint_map(t_program *game)
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
