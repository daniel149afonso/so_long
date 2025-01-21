/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:17:46 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/17 15:07:53 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	flood_fill(char **map, t_point size, t_point begin)
// {
// 	t_point	p;

// 	map[begin.x][begin.y] = 'F';
// 	if (map[begin.x][begin.y - 1] != 'F' && map[begin.x][begin.y - 1] != '1')
// 	{
// 		p.x = begin.x;
// 		p.y = begin.y - 1;
// 		flood_fill(map, size, p);
// 	}
// 	if (map[begin.x][begin.y + 1] != 'F' && map[begin.x][begin.y + 1] != '1')
// 	{
// 		p.x = begin.x;
// 		p.y = begin.y + 1;
// 		flood_fill(map, size, p);
// 	}
// 	if (map[begin.x - 1][begin.y] != 'F' && map[begin.x - 1][begin.y] != '1')
// 	{
// 		p.x = begin.x - 1;
// 		p.y = begin.y;
// 		flood_fill(map, size, p);
// 	}
// 	if (map[begin.x + 1][begin.y] != 'F' && map[begin.x + 1][begin.y] != '1')
// 	{
// 		p.x = begin.x + 1;
// 		p.y = begin.y;
// 		flood_fill(map, size, p);
// 	}
// }

void	move_y(t_game *game, t_point p, t_point begin)
{

	p.x = begin.x;
	p.y = begin.y - 1;
	if (p.y >= 0 && game->map.full[p.y][p.x] != 'F' && game->map.full[p.y][p.x] != '1')
		flood_fill(game, p);

	p.x = begin.x;
	p.y = begin.y + 1;
	if (p.y < game->map.size.y && game->map.full[p.y][p.x] != 'F' && game->map.full[p.y][p.x] != '1')
		flood_fill(game, p);
}

void	move_x(t_game *game, t_point p, t_point begin)
{
	p.x = begin.x - 1;
	p.y = begin.y;
	if (p.x >= 0 && game->map.full[p.y][p.x] != 'F' && game->map.full[p.y][p.x] != '1')
		flood_fill(game, p);
	p.x = begin.x + 1;
	p.y = begin.y;
	if (p.x < game->map.size.x && game->map.full[p.y][p.x] != 'F' && game->map.full[p.y][p.x] != '1')
		flood_fill(game, p);
}

void	is_collect_exit(t_game *game, t_point begin)
{
	if (game->map.full[begin.y][begin.x] == 'C')
	{
		game->map.collect--;
	}
	else if (game->map.full[begin.y][begin.x] == 'E')
	{
		game->map.exit--;
	}
}

void	is_item_access(t_game *game)
{
	if (game->map.collect != 0)
		ft_error("Not all collectibles are accessible.", game);
	if (game->map.exit != 0)
		ft_error("The exit is not accessible.", game);
}

void	flood_fill(t_game *game, t_point begin)
{
	t_point	p;

	if (begin.x < 0 || begin.x >= game->map.size.x || begin.y < 0 || begin.y >= game->map.size.y)
		return ;
	if (game->map.full[begin.y][begin.x] == 'F' || game->map.full[begin.y][begin.x] == '1')
		return ;
	is_collect_exit(game, begin);
	game->map.full[begin.y][begin.x] = 'F';
	//ft_put_map(game->map.full);
	//write(1, "\n", 1);
	//printf("Collect: %d, Exit: %d\n", game->map.collect, game->map.exit);
	move_y(game, p, begin);
	move_x(game, p, begin);
}
// Vérifier si la case est dans les limites de la carte
// Si la case est déjà remplie ou un mur, ne pas continuer
// Marquer la case comme remplie avec F
// Haut (y - 1), en vérifiant que y - 1 >= 0 (pas hors limite)
// Bas (y + 1), en vérifiant que y + 1 < size.y (pas hors limite)
