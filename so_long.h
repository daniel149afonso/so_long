/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/13 19:59:56 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		32

#  define IMG_HEIGHT		32
#  define IMG_WIDTH			32

#  define FRONT				1
#  define LEFT				2
#  define RIGHT				3
#  define BACK				4
# endif

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char		**full;
	int			collect;
	int			exit;
	int			players;
	t_point		player;
	t_point		size;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	int		movements;
	int		player_sprite;
	t_map	map;
	t_bool	map_alloc;
}	t_game;

//INIT GAME
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);

//INIT MAP
void	ft_init_map(char *filename, t_game *game);

//CHECK MAP
void	ft_check_arguments(int argc, char **argv, t_game *game);
void	ft_check_map(t_game *game);

//SET POSITION
void	set_player_position(t_game *game);

//FLOOD FILL
void	flood_fill(char **map, t_point size, t_point p);

//ERROR
void	ft_error(char *str, t_game *game);
void	ft_free_map(t_game *game);

//UTILS
int		ft_strlen_v2(const char *s);
int		get_height_map(char **map);
void	is_empty_string(t_game *game);
void	ft_put_map(char **map);

//GET_NEXT_LINE
char	*get_next_line(int fd);
#endif
