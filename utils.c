/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:16:30 by daniel149af       #+#    #+#             */
/*   Updated: 2025/02/17 19:20:43 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_v2(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	get_height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	ft_check_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (game->map.full[j])
	{
		i = 0;
		while (game->map.full[j][i])
		{
			c = game->map.full[j][i];
			if (c == ' ' || (c >= 9 && c <= 13))
				ft_error("No space are allowed in the map.", game);
			if (c != 'P' && c != '0' && c != '1' && c != 'C' && c != 'E')
				ft_error("Only 0, 1, C, P and E are valid characters.", game);
			i++;
		}
		j++;
	}
}

void	is_empty_line(t_game *game, char **map)
{
	if (ft_strlen_v2(*map) == 0)
	{
		free(*map);
		ft_error("The map is empty!", game);
	}
	if ((*map)[0] == '\n')
	{
		free(*map);
		ft_error("The map contains an empty first line!", game);
	}
	if (ft_strnstr(*map, "\n\n", ft_strlen(*map)) != NULL)
	{
		free(*map);
		ft_error("The map contains an empty line!", game);
	}
}
