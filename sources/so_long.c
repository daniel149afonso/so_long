/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:34:11 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/01 23:06:04 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		ft_error("Error:\n Memory allocation for game failed.", game);
	ft_memset(game, 0, sizeof(t_game));
	ft_check_arguments(argc, argv, game);
	ft_init_map(argv[1], game);
	ft_init_vars(game);
	ft_check_map(game);
	set_player_position(game);
	flood_fill(game, game->map.player);
	is_item_access(game);
	ft_init_map(argv[1], game);
	ft_count_items(game);
	set_exit_position(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify,
		ButtonPressMask, ft_close_game, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_display_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_memory(game);
	return (0);
}
//mlx_hook: permet de gérer les events
//Keypress appuie sur une touche clavier
//Destroy gere les events liés à la fermeture de la fenetre
//Expose redessine la fenetre apres avoir ete masque ou reduite
//mlx_loop: lance la boucle infini d'events
