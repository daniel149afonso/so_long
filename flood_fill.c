/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:17:46 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/13 15:06:27 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_point size, t_point player)
{
	char	c;
	t_point	p;

	c = map[player.y][player.x];
	map[player.x][player.y] = 'F';
	if (player.y > 0 && map[player.x][player.y - 1] != '1')
	{

	}
}
