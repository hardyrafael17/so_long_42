/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havoc <havoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:36:09 by havoc             #+#    #+#             */
/*   Updated: 2022/08/17 21:58:40 by havoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}
int main(int argc, char *argv[]) {
  void *mlx;
  void *mlx_win;
  t_data img;
  t_map map;

  printf("args -> %s, %d\n", argv[1], argc);
  if (argc != 2)
    exit(0); // Error Handling TODO
  map = validate_map(argv[1]);
  printf("Is map valid? %d \n", map.is_valid);
  if (!map.is_valid)
    exit(0);
  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, 920, 600, "Singleton");
  img.img = mlx_new_image(mlx, 920, 600);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                               &img.endian);
  my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
  return (0);
}
