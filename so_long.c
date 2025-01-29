/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:34:11 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/29 20:16:35 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Memory allocation for game failed.", game);
	ft_check_arguments(argc, argv, game);
	ft_init_map(argv[1], game);
	ft_init_vars(game);
	printf("Avant Check:\n");
	ft_put_map(game->map.full);
	ft_check_map(game);
	set_player_position(game);
	flood_fill(game, game->map.player);
	is_item_access(game);
	ft_init_map(argv[1], game);
	ft_count_items(game);
	printf("Après Check:\n");
	ft_put_map(game->map.full);
	ft_init_mlx(game);
	ft_init_sprites(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify,
		ButtonPressMask, ft_close_game, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_display_map, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
//mlx_hook: permet de se connecter a des events
