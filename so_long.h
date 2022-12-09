/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:00:43 by havoc             #+#    #+#             */
/*   Updated: 2022/11/24 02:57:00 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# if __linux__
#  include "libs/mlx_linux/mlx.h"
#  define UP	119
#  define DOWN	115
#  define LEFT	97
#  define RIGHT 100
#  define ESC	65307
# else 
#  include "libs/mlx/mlx.h"
#  define UP	13
#  define DOWN	1
#  define LEFT	0
#  define RIGHT 2
#  define ESC	53
# endif

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* All posible actions */
enum e_Action {left = 5, right, up, down, quit, ignore_key};

/* Action to take when setting player position */
enum e_Record {increment_all, move, init};

/* A pointer to the window and its size */
typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}				t_color;

/* all info needed for an image */
typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map {
	char		*map_string;
	int			fd;
	int			is_valid;
	size_t		height;
	size_t		width;
	size_t		collectables;
	size_t		player;
	size_t		enemies;
}				t_map;

typedef struct s_assets {
	t_image		player;
	t_image		enemy;
	t_image		exit;
	t_image		background;
	t_image		wall;
	t_image		collecatble;
	t_image		erase;
}				t_assets;

typedef struct s_record {
	size_t		collectables;
	int			game_over;
	size_t		move_count;
	size_t		stats_header_printed;
}				t_record;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_assets	image;
	t_map		map;
	t_vector	player;
	t_record	record;
}				t_program;

// FUNCTIONS
void			update_map(enum e_Action action, t_program *game);
void			ft_set_player_position(t_program *game, enum e_Record action);
void			init_game(t_program *param);
int				key_update_game(int key, void *param);
void			ft_paint_map(t_program *game);
void			ft_initialize_images(t_program *game);
int				ft_input(int key, void *program);
void			ft_check_args(int argc, char *argv[]);
int				ft_update (void *(param));
int				ft_close(void);
void			ft_handle_error(int error, const char *str_error);
void			turn_img_to_color(t_image *image, t_color color);
t_map			initialize_map(void);
t_map			ft_validate_map(char *map_file_path);
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_color		new_color(int r, int g, int b, int a);
int				ft_create_trgb(int t, int r, int g, int b);

#endif
