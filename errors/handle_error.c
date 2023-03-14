/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:59:09 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 02:59:35 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_handle_error(int error, const char *str_error)
{
	if (!str_error)
	{
		perror("Error");
		exit(error);
	}
	ft_write("Error: ", 2);
	ft_write((char *) str_error, 2);
	ft_write("\n", 22);
	exit (error);
}
