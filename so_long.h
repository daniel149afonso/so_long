/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2025/01/21 15:14:04 by daniel149af      ###   ########.fr       */
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

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COLLECT_XPM			"assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

# define KEY_W				87
# define KEY_A				65
# define KEY_S				119
# define KEY_D				119

# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

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
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		collect;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

//INIT GAME
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);

//INIT MAP
void	ft_init_map(char *filename, t_game *game);

//CHECK MAP
void	ft_check_arguments(int argc, char **argv, t_game *game);
void	ft_check_map(t_game *game);
void	ft_count_items(t_game *game);

//SET POSITION
void	set_player_position(t_game *game);

//FLOOD FILL
void	flood_fill(t_game *game, t_point begin);
void	is_item_access(t_game *game);

//HANDLE INPUT
int		ft_handle_input(int key, t_game *game);
int		key_hook(int keycode, t_game *game);

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
