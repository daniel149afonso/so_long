/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:40:19 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/26 20:36:40 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_sprite(t_game *game, int i, int j)
{
	if (game->map.full[j][i] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == COLLECT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collect.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == MAP_EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == PLAYER)
	 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_front.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
}

void	ft_display_img(t_game *game)
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

}
