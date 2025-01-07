/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:55:01 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/07 18:03:17 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map.players = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->movements = 0;
	game->map.columns = 0;
	game->player_sprite = RIGHT;
}

// void	ft_init_mlx(t_game *game)
// {
// 	game->mlx_ptr = mlx_init();
// 	if (game->mlx_ptr == NULL)
// 	{
// 		free(game->mlx_ptr);
// 		ft_error("Couldn't find mlx pointer. Try it using a VNC.", game);
// 	}
// 	game->mlx_ptr = mlx_new_window(game->mlx_ptr, \
// 	game->map.rows * IMG_WIDTH, game->map.columns * IMG_HEIGHT, "so_long");
// 	if (game->mlx_ptr == NULL)
// 	{
// 		free(game->mlx_ptr);
// 		ft_error("Couldn't create the Window", game);
// 	}
// }
//FT_INIT_MLX:
//initialise le systeme de gestion graphique
//Elle configure la fenetre
