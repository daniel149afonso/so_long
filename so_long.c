/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:34:11 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/10 18:48:31 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.full[i])
	{
		ft_putstr_fd(game->map.full[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Memory allocation for game failed.", game);
	ft_check_arguments(argc, argv, game);
	ft_init_vars(game);
	ft_init_map(argv[1], game);
	ft_put_map(game);
	ft_check_map(game);
	game->mlx_ptr = mlx_init();
	return (0);
}
