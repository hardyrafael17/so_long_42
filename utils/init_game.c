#include "../so_long.h" 

int				init_game(t_program *param)
{
		param->record.collectables = param->map.collectables;
		printf("collectables count -> %zu\n", param->record.collectables);
		return (0);
}

