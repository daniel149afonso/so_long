/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:26:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/21 15:20:05 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int key, t_game *game)
{
	if (key == 65 || key == KEY_W)
	printf("A");
	// 	ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	// if (key == KEY_LEFT || key == KEY_A)
	// 	ft_player_move(game, game->map.player.y - 1, game->map.player.x, LEFT);
	// if (key == KEY_RIGHT || key == KEY_D)
	// 	ft_player_move(game, game->map.player.y, game->map.player.x, RIGHT);
	// if (key == KEY_DOWN || key == KEY_S)
	// 	ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	// if (key == KEY_Q || key == KEY_ESC)
	// 	ft_close_game(game);
	//printf("Hello from key_hook!\n");
}

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\n");
	return (0);
}
