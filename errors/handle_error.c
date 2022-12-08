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

void	ft_handle_error(int error, const char *str_error) {
	if(!str_error)
	{
		perror("Error");
		exit(error);
	}
	printf("Error: %s.\n", str_error);
	exit (error);
}

