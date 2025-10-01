/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:33:42 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/01 23:05:14 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_wall(t_game *game)
{
	int	i;
	int	line;
	int	height;

	i = 0;
	line = game->map.size.x;
	height = game->map.size.y;
	while (i < line)
	{
		if (game->map.full[0][i] != '1'
			|| game->map.full[height - 1][i] != '1')
			ft_error("Error:\n The map is not surrounded by wall!", game);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map.full[i][0] != '1'
			|| game->map.full[i][line - 1] != '1')
			ft_error("Error:\n The map is not surrounded by wall!", game);
		i++;
	}
}

void	ft_check_rectangular(t_game *game)
{
	int		first_len;
	char	*next_line;
	int		j;

	j = 0;
	first_len = ft_strlen_v2(game->map.full[j]);
	while (game->map.full[++j])
	{
		next_line = game->map.full[j];
		if (first_len != ft_strlen_v2(next_line))
			ft_error("Error:\n The lines do not have the same length.", game);
	}
}

void	ft_check_items(t_game *game)
{
	if (game->map.players != 1)
		ft_error("Error:\n Only one player is required!", game);
	if (game->map.exit != 1)
		ft_error("Error:\n Only one exit is required!", game);
	if (game->map.collect < 1)
		ft_error("Error:\n At least one collectible is required!", game);
}

void	ft_count_items(t_game *game)
{
	int	i;
	int	j;

	game->map.players = 0;
	game->map.exit = 0;
	game->map.collect = 0;
	j = 0;
	while (game->map.full[j])
	{
		i = 0;
		while (game->map.full[j][i])
		{
			if (game->map.full[j][i] == 'P')
				game->map.players++;
			else if (game->map.full[j][i] == 'E')
				game->map.exit++;
			else if (game->map.full[j][i] == 'C')
				game->map.collect++;
			i++;
		}
		j++;
	}
	ft_check_items(game);
}

void	ft_check_map(t_game *game)
{
	ft_check_rectangular(game);
	ft_check_chars(game);
	ft_check_wall(game);
	ft_count_items(game);
}
