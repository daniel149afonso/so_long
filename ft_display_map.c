/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:40:19 by daniel149af       #+#    #+#             */
/*   Updated: 2025/02/11 15:12:24 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_sprite(t_game *game, int i, int j)
{
	if (game->player_sprite == FRONT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_front.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->player_sprite == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_left.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->player_sprite == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_right.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->player_sprite == BACK)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_back.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
}

void	ft_find_sprite(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr,
		i * IMG_WIDTH, j * IMG_HEIGHT);
	if (game->map.full[j][i] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collect.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	}
	else if (game->map.full[j][i] == MAP_EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
}

int	ft_display_map(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.full[j])
	{
		i = 0;
		while (game->map.full[j][i])
		{
			ft_find_sprite(game, i, j);
			i++;
		}
		j++;
	}
	ft_player_sprite(game, game->map.player.x, game->map.player.y);
	return (0);
}
