/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/06 21:13:18 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <Libft/libft.h>

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
	int			rows;
	int			columns;
	int			collect;
	int			exit;
	int			players;
	t_point		player;
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
//INIT MAP
char	*ft_init_map(char *filename);
//CHECK MAP
void	ft_check_arguments(int argc);
void	ft_check_map(char **map);
//ERROR
void	ft_error(char *str, t_game *game);
//UTILS
int		ft_strlen_v2(const char *s);
int		is_empty_string(const char *str);
#endif
