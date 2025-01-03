/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:46:17 by daniel149af       #+#    #+#             */
/*   Updated: 2024/12/30 15:52:41 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *filename)
{
	int		map_fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	map_fd = open(filename, O_RDONLY);
	if (map_fd < 0)
		ft_error("The Map can't be opened. Does your map file exist?");
	map = ft_strdup("");
	while (1 == 1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(map_fd);
	return (map);
}
