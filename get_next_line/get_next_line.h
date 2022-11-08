/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:22:33 by hjimenez          #+#    #+#             */
/*   Updated: 2022/08/10 13:02:08 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "../libs/libft/libft.h"

typedef struct fd_data_list
{
	int			fd;
	char		*left_over;
	int			eof;
	int			return_null;
	int			s_length;
	char		*to_return;
	char		*to_free;
}				t_fd;

size_t			ft_check_nl(char *read_buffer, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t count, size_t size);
char			*get_next_line(int fd);
int				ft_append(char *to_append, t_fd *buffer_to_update);
char			*ft_return_line(t_fd *buffer_to_update);
void			ft_read(t_fd *t_fd_data, int fd);
size_t			ft_strlcpy_strlen(char *dst, const char *src, size_t size);

#endif
