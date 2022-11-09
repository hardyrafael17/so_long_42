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
  signed int	from_x;
  signed int	from_y;
  signed int	to_x;
  signed int	to_y;
}				t_position;

void	modify_map(t_position position, t_program game) {
  //validate next move;
  //update display after completing change
  if(game.map.is_valid && position.from_x)
	return; 
  return;
}
