/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:09:26 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:11:47 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*check_items(t_map *map)
{
	check_each_item(map);
	if (!map->is_valid || map->collectables < 1 || \
		map->player != 1 || map->exit != 1)
	{
		free(map->map_string);
		map->is_valid = 0;
	}
	return (map);
}

static void	check_borders(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map->map_string)
	{
		map->is_valid = 0;
		return ;
	}
	while (map->map_string[i])
	{
		if (i < map->width - 2 && map->map_string[i] != '1')
				map->is_valid = 0;
		if (i > (map->width * map->height) - map->width && i < (map->width \
			* map->height) - 2 && map->map_string[i] != '1')
				map->is_valid = 0;
		if ((i + 2) % map->width == 0 && map->map_string[i] != '1')
				map->is_valid = 0;
		if (i % map->width == 0 && map->map_string[i] != '1')
				map->is_valid = 0;
		++i;
	}
	if (!map->is_valid)
		free(map->map_string);
}

t_map	initialize_map(void)
{
	t_map	map;

	map.width = 0;
	map.height = 0;
	map.exit = 0;
	map.collectables = 0;
	map.player = 0;
	map.is_valid = 1;
	map.map_string = NULL;
	return (map);
}

static	int	check_line(t_map *map, char *line)
{
	char	*line_holder;

	if (!line)
		return (0);
	if (!map->width)
		map->width = ft_strlen(line);
	if (line[map->width - 1] != '\n')
	{
		line_holder = line;
		line = ft_strjoin(line, "\n");
		free(line_holder);
	}
	if (map->width != ft_strlen(line))
	{
		map->is_valid = 0;
		return (0);
	}
	if (!map->map_string)
		check_line_helper1(map, line);
	else
		check_line_helper(map, line);
	map->height++;
	return (1);
}

t_map	ft_validate_map(char *map_file_path)
{
	char	*new_line;
	t_map	map;

	map = initialize_map();
	map.fd = open(map_file_path, O_RDONLY);
	if (map.fd == -1)
		ft_handle_error(6, NULL);
	new_line = get_next_line(map.fd);
	while (check_line(&map, new_line))
		new_line = get_next_line(map.fd);
	close(map.fd);
	check_borders(&map);
	if (!map.is_valid)
		ft_handle_error(2, "Error: Invalid Map Borders, must be all 1\n");
	check_items(&map);
	if (!map.is_valid)
		ft_handle_error(2, "Error: Invalid map configuration\n");
	return (map);
}
