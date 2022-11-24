/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:12:08 by hjimenez          #+#    #+#             */
/*   Updated: 2022/11/24 03:12:22 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

int	init_game(t_program *param)
{
	param->record.collectables = param->map.collectables;
	printf("collectables count -> %zu\n", param->record.collectables);
	return (0);
}
