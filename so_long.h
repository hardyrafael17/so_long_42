/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:00:43 by havoc             #+#    #+#             */
/*   Updated: 2022/08/10 16:23:15 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
  char *map_string;
  int fd;
  int is_valid;
  size_t height;
  size_t width;
  size_t collectables;
  size_t player;
  size_t enemies;
} t_map;

t_map validate_map(char *map_file_path);
t_map initialize_map();

#endif
