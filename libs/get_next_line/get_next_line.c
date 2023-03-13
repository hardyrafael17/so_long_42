/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:13:09 by hjimenez          #+#    #+#             */
/*   Updated: 2022/08/10 13:06:09 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_fd		*fd_list_data;
	static void	*fd_keep[1024];
	int			i;

	fd_list_data = NULL;
	i = 0;
	while (*(fd_keep + i) && !fd_list_data)
	{
		if (*(fd_keep + i) != (void *)1)
			if (((t_fd *) *(fd_keep + i))->fd == fd)
				fd_list_data = (t_fd *) *(fd_keep + i);
		++i;
	}
	if (!fd_list_data)
		fd_list_data = ft_calloc(1, sizeof(t_fd));
	ft_read(fd_list_data, fd);
	*(fd_keep + i) = fd_list_data;
	fd_list_data->to_return = ft_return_line(fd_list_data);
	if (!fd_list_data->to_return)
	{
		*(fd_keep + i) = (void *)1;
	}
	return (fd_list_data->to_return);
}

size_t	ft_check_nl(char *read_buffer, size_t size)
{
	size_t	i;

	i = 0;
	if (!read_buffer)
		return (i);
	while (i < size && *(read_buffer + i) != 0)
	{
		if (*(read_buffer + i) == '\n')
		{
			++i;
			return (i);
		}
		++i;
	}
	i = 0;
	return (i);
}

int	ft_append(char *to_append, t_fd *update_bf)
{
	char	*to_free;

	if (!update_bf->left_over)
		update_bf->left_over = ft_strjoin("", to_append);
	else
	{
		to_free = update_bf->left_over;
		update_bf->left_over = ft_strjoin(update_bf->left_over, to_append);
		free(to_free);
	}
	free(to_append);
	return (0);
}

char	*ft_return_line(t_fd *b_update)
{
	size_t	nl_index;

	b_update->to_free = b_update->left_over;
	if (!b_update->left_over)
	{
		free(b_update);
		return (NULL);
	}
	b_update->s_length = ft_strlcpy_strlen(NULL, b_update->left_over, 0);
	nl_index = ft_check_nl(b_update->left_over, b_update->s_length);
	if (b_update->eof == 1 && nl_index == 0)
	{
		if (b_update->s_length == 0)
		{
			free(b_update->to_free);
			free(b_update);
			return (NULL);
		}
		b_update->left_over = NULL;
		return (b_update->to_free);
	}
	b_update->to_return = ft_substr(b_update->left_over, 0, nl_index);
	b_update->left_over = ft_strjoin("", b_update->left_over + nl_index);
	free(b_update->to_free);
	return (b_update->to_return);
}

void	ft_read(t_fd *fd_list_data, int fd)
{
	char			*read_buffer;
	size_t			nl_index;

	if (!fd_list_data)
		return ;
	fd_list_data->fd = fd;
	while (!fd_list_data->eof)
	{
		read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!read_buffer)
			return ;
		fd_list_data->eof = read(fd, read_buffer, BUFFER_SIZE);
		nl_index = ft_check_nl(read_buffer, BUFFER_SIZE);
		ft_append(read_buffer, fd_list_data);
		if (fd_list_data->eof > 0)
			fd_list_data->eof = 0;
		else
			fd_list_data->eof = 1;
		if (nl_index != 0 || fd_list_data->eof)
		{
			break ;
		}
	}
}
