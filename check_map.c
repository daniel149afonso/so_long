/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:33:42 by daniel149af       #+#    #+#             */
/*   Updated: 2024/12/29 00:57:34 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		if (map[0][i] != '1' || map[get_height_map(map) - 1][i] != '1')
			ft_error("The wall is not 1!");
		i++;
	}
	i = 0;
	j = 0;
	while (map[j][i])
	{
		if (map[j][0] != '1' || map[i][ft_strlen(map[j]) - 1] != '1')
			ft_error("The wall is not 1!");
		j++;
	}
}

void	check_arguments(int argc)
{
	if (argc < 2)
		ft_error("The map is missing!");
	if (argc > 2)
		ft_error("Too many arguments, only two arguments are required!");
}
