/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:17:46 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/14 15:09:15 by daniel149af      ###   ########.fr       */
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

void	flood_fill(char **map, t_point size, t_point begin)
{
    t_point p;

	printf("%d %d %c\n", begin.y, begin.x, map[begin.y][begin.x]);
    // Vérifier si la case est dans les limites de la carte
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
	{
		printf("bonjour");
		return;  // Sortir si la case est hors des limites
	}


    // Si la case est déjà remplie ou un mur, ne pas continuer
    if (map[begin.y][begin.x] == 'F' || map[begin.y][begin.x] == '1')
    {
		printf("salut");
		return;  // Sortir si la case est hors des limites
	}

    // Marquer la case comme remplie
    map[begin.y][begin.x] = 'F';
	ft_put_map(map);
	write(1, "\n", 1);
    // Exploration des 4 directions

    // Haut (y - 1), en vérifiant que y - 1 >= 0 (pas hors limite)
    p.x = begin.x;
    p.y = begin.y - 1;
    if (p.y >= 0 && map[p.y][p.x] != 'F' && map[p.y][p.x] != '1')
        flood_fill(map, size, p);

    // Bas (y + 1), en vérifiant que y + 1 < size.y (pas hors limite)
    p.x = begin.x;
    p.y = begin.y + 1;
    if (p.y < size.y && map[p.y][p.x] != 'F' && map[p.y][p.x] != '1')
        flood_fill(map, size, p);

    // Gauche (x - 1), en vérifiant que x - 1 >= 0 (pas hors limite)
    p.x = begin.x - 1;
    p.y = begin.y;
    if (p.x >= 0 && map[p.y][p.x] != 'F' && map[p.y][p.x] != '1')
        flood_fill(map, size, p);

    // Droite (x + 1), en vérifiant que x + 1 < size.x (pas hors limite)
    p.x = begin.x + 1;
    p.y = begin.y;
    if (p.x < size.x && map[p.y][p.x] != 'F' && map[p.y][p.x] != '1')
        flood_fill(map, size, p);
}

