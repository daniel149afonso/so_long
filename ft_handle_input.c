/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:26:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/21 21:23:41 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_move(t_game *game, int new_y, int new_x, int dir)
{
	int	last_x;
	int	last_y;

	if (game->map.full[new_y][new_x] == MAP_EXIT || )
	game->map.player.y = y;
	game->map.player.x = x;
	printf("y: %d, x: %d\n", game->map.player.y, game->map.player.x);
}

int	ft_handle_input(int key, t_game *game)
{
	if (key == KEY_UP || key == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (key == KEY_LEFT || key == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (key == KEY_RIGHT || key == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (key == KEY_DOWN || key == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, BACK);
	if (key == KEY_ESC)
		ft_close_game(game);
}


