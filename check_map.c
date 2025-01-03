/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:33:42 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/03 16:37:30 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc, char **argv)
{
	int	filename_len;

	if (argc < 2)
		ft_error("The map is missing!");
	if (argc > 2)
		ft_error("Too many arguments, only two arguments are required!");
	filename_len = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][filename_len - 4], ".ber", 4))
		ft_error("Wrong extension file. It should be.ber");
}

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
		if (map[j][0] != '1' || map[j][ft_strlen(map[i]) - 1] != '1')
			ft_error("The wall is not 1!");
		j++;
	}
}

void	check_rectangular(char **map)
{
	char	*first_len;
	char	*next_line;
	int		j;

	j = 0;
	first_len = ft_strlen(map[j]);
	while (map[++j])
	{
		next_line = map[j];
		if (first_len != ft_strlen(next_line))
			ft_error("The lines do not have the same length.");
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
	check_items(game->players, game->exit, game->collect);
}

void	check_items(int player, int exit, int collect)
{
	if (player != 1)
		ft_error("Only one player is required!");
	if (exit != 1)
		ft_error("Only one exit is required!");
	if (collect < 1)
		ft_error("At least one collectible is required!");
}

void	check_map(char **map, t_game *game)
{
	check_rectangular(map);
	check_wall(map);
	count_items(map, game);
}
