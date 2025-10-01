/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:46:17 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/01 23:05:48 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	int	filename_len;

	game->map_alloc = false;
	if (argc < 2)
		ft_error("Error:\n The map is missing!", game);
	if (argc > 2)
		ft_error("Error:\n Too many arguments, only two arguments are required!",
			game);
	filename_len = ft_strlen_v2(argv[1]);
	if (!ft_strnstr(&argv[1][filename_len - 4], ".ber", 4))
		ft_error("Error:\n Wrong extension file. It should be '.ber'", game);
}

void	ft_init_map(char *filename, t_game *game)
{
	int		map_fd;
	char	*map;

	map = NULL;
	map_fd = open(filename, O_RDONLY);
	if (map_fd < 0)
		ft_error("Error:\n The Map can't be opened. Does your map file exist?",
			game);
	if (game->map_alloc)
		ft_free_map(game);
	ft_get_map(game, &map, map_fd);
	close(map_fd);
	is_empty_line(game, &map);
	game->map.full = ft_split(map, '\n');
	free(map);
	if (!game->map.full)
		ft_error("Error:\n Failed to allocate full map with split function",
			game);
	game->map_alloc = true;
}

void	ft_get_map(t_game *game, char **map, int map_fd)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	*map = ft_strdup("");
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		tmp = *map;
		*map = ft_strjoin(*map, line);
		free(tmp);
		if (!*map)
			ft_error("Error:\n Memory allocation for line failed.", game);
		free(line);
		i++;
	}
}
