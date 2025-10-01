/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:26:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/01 23:05:35 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player_sprite(t_game *game, int last_x, int last_y)
{
	int	dir_x;
	int	dir_y;

	dir_x = game->map.player.x - last_x;
	dir_y = game->map.player.y - last_y;
	if (dir_x == -1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_left.xpm_ptr, game->map.player.x * IMG_WIDTH,
			game->map.player.y * IMG_HEIGHT);
	else if (dir_x == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_right.xpm_ptr, game->map.player.x * IMG_WIDTH,
			game->map.player.y * IMG_HEIGHT);
	else if (dir_y == -1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_back.xpm_ptr, game->map.player.x * IMG_WIDTH,
			game->map.player.y * IMG_HEIGHT);
	else if (dir_y == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_front.xpm_ptr, game->map.player.x * IMG_WIDTH,
			game->map.player.y * IMG_HEIGHT);
}

void	ft_handle_move(t_game *game, int last_x, int last_y)
{
	if (game->map.full[game->map.player.y][game->map.player.x] == COLLECT
	|| game->map.full[game->map.player.y][game->map.player.x] == FLOOR)
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[game->map.player.y][game->map.player.x] == COLLECT)
			game->map.collect--;
		game->movements++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->floor.xpm_ptr, last_x * IMG_WIDTH, last_y * IMG_HEIGHT);
		ft_player_sprite(game, last_x, last_y);
		ft_show_movements(game->movements);
	}
	if (game->map.collect == 0)
		ft_show_exit(game);
}

void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == WALL)
		return ;
	game->map.player.x = new_x;
	game->map.player.y = new_y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.collect == 0)
	{
		game->movements++;
		ft_close_game(game);
	}
	ft_handle_move(game, last_x, last_y);
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
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (key == KEY_ESC)
		ft_close_game(game);
	return (0);
}
//Recupere les inputs de user et met a jour
//la position du joueur et un peu les sprites
//la map nest plus mise a jour mais seulement les cases
//correspondante au mouvements