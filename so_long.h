/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/03 16:37:09 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	int		players;
	int		collect;
	int		exit;
	int		columns;
	int		rows;
	t_point	player;
}	t_game;

//READ MAP
char	*read_map(char *filename);
//CHECKS
void	check_arguments(int argc);
void	check_wall(char **map);
void	check_rectangular(char **map);
void	count_items(char **map);
//ERROR
void	ft_error(char *str);
//UTILS
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
#endif
