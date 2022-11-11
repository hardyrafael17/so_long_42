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

void	modify_map(t_position position, t_program game) {

				
			//validate next move;
			//update display after completing change
			if(game.map.is_valid && position.from_x)
			return; 
}
