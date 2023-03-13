/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:39:39 by hjimenez          #+#    #+#             */
/*   Updated: 2022/02/28 16:59:26 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlcpy_strlen(NULL, s1, 0) + ft_strlcpy_strlen(NULL, s2, 0)) + 1;
	joined = ft_calloc(len, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcat(joined, s1, len);
	ft_strlcat(joined, s2, len);
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_size_str;

	if (!s)
		return (NULL);
	s_size_str = ft_strlcpy_strlen(NULL, s, 0);
	if (len > s_size_str)
		substring = ft_calloc(s_size_str, sizeof(char));
	else
		substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	if (start > s_size_str)
		return (substring);
	if (!ft_strlcpy_strlen(substring, s + start, len + 1))
		return (NULL);
	return (substring);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlcpy_strlen(NULL, src, 0);
	dest_length = ft_strlcpy_strlen(NULL, dst, 0);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

size_t	ft_strlcpy_strlen(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst && size == 0)
	{
		j = 0;
		while (src[j] != 0)
			j++;
		return (j);
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
