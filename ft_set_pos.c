/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:17:01 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/13 20:01:28 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(char c, int i, int j, t_game *game)
{
	if (c == 'P')
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