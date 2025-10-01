/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:40:19 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/02 00:51:24 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_find_sprite(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr,
		i * IMG_WIDTH, j * IMG_HEIGHT);
	if (game->map.full[j][i] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	else if (game->map.full[j][i] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collect.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
	}
	if (game->map.full[j][i] == PLAYER)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_front.xpm_ptr, i * IMG_WIDTH, j * IMG_HEIGHT);
}

int	ft_display_map(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
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
	return (0);
}

void	ft_show_exit(t_game *game)
{
	game->map.full[game->map.exit_pos.y][game->map.exit_pos.x] = MAP_EXIT;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->exit.xpm_ptr, game->map.exit_pos.x * IMG_WIDTH,
		game->map.exit_pos.y * IMG_HEIGHT);
}

void	ft_show_movements(int nb)
{
	char	*movements;
	char	*sentence;

	movements = ft_itoa(nb);
	sentence = ft_strjoin("Movements: ", movements);
	ft_putstr_fd(sentence, 1);
	write(1, "\n", 1);
	free(movements);
	free(sentence);
}
//La map est affiche une seule fois au debut et nest plus
//mis a jour a chaque mouvement du joueur
//(evite le reaffichage inutile de toute la map)