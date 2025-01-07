/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:55:01 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/06 20:52:31 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->players = 0;
	game->collect = 0;
	game->exit = 0;
	game->movements = 0;
	game->columns = 0;
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
	game->mlx_ptr = mlx_new_window(game->mlx_ptr, \
	game->rows * IMG_WIDTH, game->columns * IMG_HEIGHT, "so_long");
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error("Couldn't create the Window", game);
	}
}
//FT_INIT_MLX:
//initialise le systeme de gestion graphique
//Elle configure la fenetre
