#include "../so_long.h"

t_vector	get_coordenates(t_program *game, size_t target)
{
		size_t		x;
		size_t		y;
		t_vector	vector; 
		
		x = (target / game->map.width);
		y = (target % game->map.width);
		printf("x=> %d, y%d\n", (int) x, (int) y);
		vector.x = x;
		vector.y = y;
		return (vector);
}

void	set_player_position(t_program *game)
{
		size_t		count;
		
		count = 0;
		while (game->map.map_string[count])
		{
				if(game->map.map_string[count] == 'P')	
				{
						game->player = get_coordenates(game, count);;
						return;
				}
				count++;
		}
}
