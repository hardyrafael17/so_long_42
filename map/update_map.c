#include "../so_long.h"

// typedef struct s_assets {
// 	t_image		player;
// 	t_image		enemy;
// 	t_image		exit;
// 	t_image		background;
// 	t_image		wall;
// 	t_image		collecatble;
// }				t_assets;

typedef	struct	s_position {
		size_t	from_x;
		size_t	from_y;
    size_t	to_x;
		size_t 	to_y;
}				t_position;

// t_vector up(){

// }

void	update_map(enum Action action, t_program *param)
{
		t_vector *current_xy;
		// t_vector	next_xy;

		// size_t		x;
		// size_t		y;
		size_t		string_index;


		current_xy = &param->player;
		if (action == right)
		{
				string_index = (param->player.y * param->map.width) + current_xy->x + 1;
				if(param->map.map_string[string_index] == '0')
				{
						param->map.map_string[string_index] = 'P';
						param->map.map_string[string_index - 1] = '0';
				} else {
						printf("character found ->%c, map width -> %zu,\n", param->map.map_string[string_index - 1], param->map.width);
						param->map.map_string[string_index - 1] = '+';
				}
		}
		// if (action == left)
		// {
		// 		string_index = (param->player.y * param->map.width) + current_xy->y - 1;
		// 		if(param->map.map_string[string_index] == '0')
		// 		{
		// 				param->map.map_string[string_index] = 'P';
		// 				param->map.map_string[string_index + 1] = '0';
		// 		}
		// }
		printf("x => %d, y => %d, ---> %zu, \n", current_xy->x, current_xy->y, string_index);
		printf("%s", param->map.map_string);
}
