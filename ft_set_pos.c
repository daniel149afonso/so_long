/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:17:01 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/31 17:15:01 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(char c, int i, int j, t_game *game)
{
	if (c == PLAYER)
	{
		game->map.player.x = i;
		game->map.player.y = j;
	}
}

void	set_player_position(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.full[j])
	{
		i = 0;
		while (game->map.full[j][i])
		{
			player_position(game->map.full[j][i], i, j, game);
			i++;
		}
		j++;
	}
}
