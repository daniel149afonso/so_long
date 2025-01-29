/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:07:49 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/29 20:14:21 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_memory(t_game *game)
{
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_alloc == true)
	{
		while (game->map.full[i])
		{
			free(game->map.full[i]);
			i++;
		}
		free(game->map.full);
	}
}

void	ft_error(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	ft_free_map(game);
	exit(EXIT_FAILURE);
}
