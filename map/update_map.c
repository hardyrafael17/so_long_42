#include "../so_long.h"


void	update_map(enum Action action, t_program *param)
{
		t_vector *current_xy;
		size_t		string_index;

		current_xy = &param->player;
		string_index = (param->player.y * param->map.width) + current_xy->x;
		if (action == right)
		{
				if(param->map.map_string[string_index + 1] == '0')
				{
						param->map.map_string[string_index] = '0';
						param->map.map_string[string_index + 1] = 'P';
				}
		}
		if (action == left)
		{
				printf("left");
				if(param->map.map_string[string_index - 1] == '0')
				{
						param->map.map_string[string_index] = '0';
						param->map.map_string[string_index - 1] = 'P';
				}
		}
		if (action == up)
		{
				if(param->map.map_string[string_index - param->map.width] == '0')
				{
						param->map.map_string[string_index] = '0';
						param->map.map_string[string_index - param->map.width] = 'P';
				}
		}
		if (action == down)
		{
				if(param->map.map_string[string_index + param->map.width] == '0')
				{
						param->map.map_string[string_index] = '0';
						param->map.map_string[string_index + param->map.width] = 'P';
				}
		}
		printf("character found ->%c, map width -> %zu,\n", param->map.map_string[string_index], param->map.width);
		set_player_position(param);
		paint_map(param);
		printf("x => %d, y => %d, ---> %zu, \n", current_xy->x, current_xy->y, string_index);
		printf("%s", param->map.map_string);
}
