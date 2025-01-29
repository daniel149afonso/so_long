/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:40:19 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/29 01:50:56 by daniel149af      ###   ########.fr       */
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
}

void	ft_find_sprite(t_game *game, int i, int j)
{
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	if (game->map.full[j][i] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	if (game->map.full[j][i] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == COLLECT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collect.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == MAP_EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == PLAYER)
		ft_player_sprite(game, i, j);
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
	return (0);
}
