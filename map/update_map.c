#include "../so_long.h"

static void	ft_direction(size_t index, signed int direction, t_program *param)
{
		if(param->map.map_string[index + direction] == '0')
		{
				param->map.map_string[index] = '0';
				param->map.map_string[index + direction] = 'P';
				set_player_position(param);
				paint_map(param);
		} else if (param->map.map_string[index + direction] == 'C')
		{
				param->record.collectables--;
				printf("collectables count -> %zu\n", param->record.collectables);
				param->map.map_string[index] = '0';
				param->map.map_string[index + direction] = 'P';
				set_player_position(param);
				paint_map(param);
		} else if (param->map.map_string[index + direction] == 'E' \
				&& param->record.collectables == 0)
		{
				param->record.game_over = 1;
				param->map.map_string[index] = '0';
				param->map.map_string[index + direction] = 'P';
				set_player_position(param);
				paint_map(param);
		}// In case of goal, end game
}

void	update_map(enum Action action, t_program *param)
{
		t_vector *current_xy;
		size_t		string_index;

		current_xy = &param->player;
		string_index = (param->player.y * param->map.width) + current_xy->x;
		if (action == right)
				ft_direction(string_index, 1, param);
		if (action == left)
				ft_direction(string_index, -1, param);
		if (action == up)
				ft_direction(string_index, - param->map.width, param);
		if (action == down)
				ft_direction(string_index, param->map.width, param);
}
