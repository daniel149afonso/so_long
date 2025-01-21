/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:55:01 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/21 15:12:07 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map.players = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->movements = 0;
	game->map.size.x = ft_strlen_v2(game->map.full[0]);
	game->map.size.y = get_height_map(game->map.full);
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	//void	*img;

	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
	640, 480, "so_long");
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error("Couldn't create the Window", game);
	}
}

// void	ft_init_sprites(t_game *game)
// {
// 	void	*mlx;

// 	mlx = game->mlx_ptr;
// 	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
// 	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
// 	game->collect = ft_new_sprite(mlx, COLLECT_XPM, game);
// 	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
// 	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
// 	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
// 	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
// 	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
// 	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
// }

// t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
// {
// 	t_image	sprite;

// 	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
// 	if (sprite.xpm_ptr == NULL)
// 		ft_error("Couldn't find a sprite. Does it exist?", game);
// 	return (sprite);
// }
//FT_INIT_MLX:
//initialise le systeme de gestion graphique
//Elle configure la fenetre
