/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:17:46 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/13 15:26:34 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_point size, t_point player)
{
	char	c;
	t_point	p;
	char	**tmp;

	tmp = map;
	c = tmp[player.y][player.x];
	tmp[player.x][player.y] = 'F';
	if (player.y > 0 && tmp[player.x][player.y - 1] != 'F')
	{
		p.x = player.x;
		p.y = player.y - 1;
		flood_fill(tmp, size, p);
	}
	else if (player.x > 0 && tmp[player.x][player.y] != 'F')
	{
		p.x = player.x - 1;
		p.y = player.y;
		flood_fill(tmp, size, p);
	}
	else if (player.x < ft_strlen(tmp[0]) - 1 && tmp[player.x][player.y] != 'F')
	{
		p.x = player.x - 1;
		p.y = player.y;
		flood_fill(tmp, size, p);
	}
}
