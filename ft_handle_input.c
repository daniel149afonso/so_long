/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:26:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/26 20:44:30 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_show_movements(int nb)
{
	char	*movements;

	movements = ft_itoa(nb);
	movements = ft_strjoin("Movements: ", movements);
	ft_putstr_fd(movements, 1);
	write(1, "\n", 1);
	free(movements);
}

void	ft_player_move(t_game *game, int new_y, int new_x, int dir)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.collect == 0)
		ft_close_game(game);
	else if (game->map.full[new_y][new_x] == COLLECT
	|| game->map.full[new_y][new_x] == FLOOR)
	{
		if (game->map.full[new_y][new_x] == COLLECT)
			game->map.collect--;
		game->map.full[last_y][last_x] = FLOOR;
		game->map.player.y = new_y;
		game->map.player.x = new_x;
		game->map.full[game->map.player.y][game->map.player.x] = PLAYER;
		game->movements++;
		ft_put_map(game->map.full);
		printf("y: %d, x: %d\n", game->map.player.y, game->map.player.x);
		ft_show_movements(game->movements);
	}

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
	return (0);
}


