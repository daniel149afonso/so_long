/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:46:17 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/06 21:17:35 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	int	filename_len;

	game->map_alloc = false;
	if (argc < 2)
		ft_error("The map is missing!", game);
	if (argc > 2)
		ft_error("Too many arguments, only two arguments are required!", game);
	filename_len = ft_strlen_v2(argv[1]);
	if (ft_strnstr(&argv[1][filename_len - 4], ".ber", 4))
		ft_error("Wrong extension file. It should be.ber", game);
}

void	*ft_init_map(char *filename, t_game *game)
{
	int		map_fd;
	char	*map;
	char	*line;
	int		i;

	i = 0;
	map_fd = open(filename, O_RDONLY);
	if (map_fd < 0)
		ft_error("The Map can't be opened. Does your map file exist?", game);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		map = ft_strjoin(&map, line);
		if (!map)
			ft_error("Memory allocation for line failed.", game);
		free(line);
		i++;
	}
	close(map_fd);
	game->map.full = ft_split(map, "\n");
	game->map_alloc = true;
	free(map);
}
