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

void	check_line_helper1(t_map *map, char *line)
{
	map->map_string = ft_strjoin(line, "");
	free(line);
}

void	check_line_helper(t_map *map, char *line)
{
	char	*line_holder;

	line_holder = map->map_string;
	map->map_string = ft_strjoin(map->map_string, line);
	free (line_holder);
	free(line);
}

t_map	*check_each_item(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map_string[i])
	{
		if (map->map_string[i] == 'C')
			map->collectables++;
		else if (map->map_string[i] == 'P')
			map->player++;
		else if (map->map_string[i] == 'E')
			map->exit++;
		else if (map->map_string[i] == '1' || map->map_string[i] == '0' \
			|| map->map_string[i] == '\n')
		{
			++i;
			continue ;
		}
		else
		{
		map->is_valid = 0;
			return (map);
		}
		++i;
	}
	return (map);
}
