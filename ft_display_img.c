/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:40:19 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/26 15:17:21 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_sprite(t_game *game, t_image sprite, int i, int j)
{
	if (game->map.full[j][i] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == MAP_EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
}

void	ft_display_img(t_image sprite, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.full[j])
	{
		i = 0;
		while (game->map.full[j][i])
		{
			if (game->map.full[j][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, i * 16, j * 16);
			i++;
		}
		j++;
	}

}
