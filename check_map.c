/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:33:42 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/06 20:55:14 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(char **map, t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		if (map[0][i] != '1' || map[get_height_map(map) - 1][i] != '1')
			ft_error("The wall is not 1!", game);
		i++;
	}
	i = 0;
	j = 0;
	while (map[j][i])
	{
		if (map[j][0] != '1' || map[j][ft_strlen_v2(map[i]) - 1] != '1')
			ft_error("The wall is not 1!", game);
		j++;
	}
}

void	check_rectangular(char **map, t_game *game)
{
	char	*first_len;
	char	*next_line;
	int		j;

	j = 0;
	first_len = ft_strlen_v2(map[j]);
	while (map[++j])
	{
		next_line = map[j];
		if (first_len != ft_strlen_v2(next_line))
			ft_error("The lines do not have the same length.", game);
	}
}

void	count_items(char **map, t_game *game)
{
	int	i;
	int	j;

	game->players = 0;
	game->exit = 0;
	game->collect = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				game->players++;
			if (map[j][i] == 'E')
				game->exit++;
			if (map[j][i] == 'C')
				game->collect++;
			i++;
		}
		j++;
	}
	check_items(game->players, game->exit, game->collect, game);
}

void	check_items(int player, int exit, int collect, t_game *game)
{
	if (player != 1)
		ft_error("Only one player is required!", game);
	if (exit != 1)
		ft_error("Only one exit is required!", game);
	if (collect < 1)
		ft_error("At least one collectible is required!", game);
}

void	ft_check_map(t_game *game)
{
	check_rectangular(map);
	check_wall(map);
	count_items(map, game);
	is_empty_string(map);
}
