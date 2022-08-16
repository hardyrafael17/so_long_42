#include "so_long.h"

t_map check_items(t_map map)
{
	size_t	i;

	i = 0;
	if(!map.is_valid)
		return (map);
	while(map.map_string[i])	
	{
		if(map.map_string[i] == 'C')
			map.collectables++;
		if(map.map_string[i] == 'P')
			map.player++;
		if(map.map_string[i] == 'E')
			map.enemies++;
		if(map.map_string[i] == '1' || map.map_string[i] == '0')
			continue;
		else
		{
			map.is_valid = 0;
			return (map);
		}
		++i;
	}
	if (map.collectables < 1 || map.player != 1)
		map.is_valid = 0;
	return (map);
}

void check_borders(t_map map)
{
	size_t	i;

	i = 0;
	if(!map.map_string)
		return;
	while(map.map_string[i])
	{
		if(i < map.width - 2 && map.map_string[i] != '1')
			map.is_valid = 0;
		if(i > (map.width * map.height) - map.width && i < (map.width * map.height) - 2 && map.map_string[i] != '1')
			map.is_valid = 0;
		if((i + 2)%map.width == 0 && map.map_string[i] != '1')
			map.is_valid = 0;
		if(i%map.width == 0 && map.map_string[i + 1] != '1')
			map.is_valid = 0;
	}
}

t_map	initialize_map()
{
	t_map	map;
	map.width = 0;
	map.height = 0;
	map.enemies = 0;
	map.collectables = 0;
	map.player = 0;
	map.is_valid = 1;

	return(map);
}

int check_line(t_map map, char *line)
{
	char	*line_holder;
	if(!line)
		return (0);
	if(!map.width)
		map.width = ft_strlen(line);
	if(line[map.width -1] != '\n')
	{
		printf("completing last line\n");
		line_holder = line;
		line = ft_strjoin(line, "\n");	
		free(line_holder);
	}
	if(map.width != ft_strlen(line))
	{
		map.is_valid = 0;
		return (0);
	}
	if(!map.map_string)
	{
		map.map_string = ft_strjoin(line, "");
		free(line);
	}
	else
	{
		line_holder = map.map_string;
		map.map_string = ft_strjoin(map.map_string, line);
		free (line_holder);
	}
	map.height++;
	return (1);
}

t_map validate_map(char *map_file_path)
{
	char	*new_line;
	t_map	map;	
	map = initialize_map();
	if(map_file_path)
		map.fd = open("map.file_path", O_RDONLY);
	if(map.fd == -1)
		map.is_valid = 0;
	new_line = get_next_line(map.fd);
	 while(check_line(map, new_line))
		new_line = get_next_line(map.fd);	
	check_borders(map);	
	check_items(map);
	return (map);
}
