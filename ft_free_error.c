/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:07:49 by daniel149af       #+#    #+#             */
/*   Updated: 2025/02/02 16:57:14 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_memory(t_game *game)
{
	if (!game)
		return ;
	ft_destroy_img(game);
	ft_free_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collect.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return ;
	i = 0;
	if (game->map_alloc == true)
	{
		while (game->map.full[i])
		{
			free(game->map.full[i]);
			i++;
		}
	}
	free(game->map.full);
	game->map.full = NULL;
	game->map_alloc = false;
}

void	ft_error(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	ft_free_map(game);
	exit(EXIT_FAILURE);
}
//mlx_destroy_display:
//libere toutes les ressources d'affichage créées par la mlx_init
//sauf le pointeur lui-même
