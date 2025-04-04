/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2025/02/19 21:04:44 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

# define BUFFER_SIZE		32

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define PLAYER				'P'
# define WALL				'1'
# define FLOOR				'0'
# define COLLECT			'C'
# define MAP_EXIT			'E'

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define KEY_UP				65362
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_DOWN			65364

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC			65307

# define WALL_XPM			"assets/sprites/wall/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor/floor.xpm"
# define COLLECT_XPM		"assets/sprites/collect/collect.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define EXIT_XPM	"assets/sprites/exit/exit.xpm"

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
	t_point		exit_pos;
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
	t_image		exit;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

//INIT GAME
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);

//INIT MAP
void	ft_init_map(char *filename, t_game *game);
void	ft_get_map(t_game *game, char **map, int map_fd);

//CHECK MAP
void	ft_check_arguments(int argc, char **argv, t_game *game);
void	ft_check_map(t_game *game);
void	ft_count_items(t_game *game);

//SET POSITION
void	set_player_position(t_game *game);
void	set_exit_position(t_game *game);

//FLOOD FILL
void	flood_fill(t_game *game, t_point begin);
void	is_item_access(t_game *game);

//HANDLE INPUT
int		ft_handle_input(int key, t_game *game);
int		key_hook(int keycode, t_game *game);
void	ft_show_movements(int nb);

//DISPLAY IMAGE
int		ft_display_map(t_game *game);
void	ft_player_sprite(t_game *game, int last_x, int last_y);
void	ft_show_movements(int nb);
void	ft_show_exit(t_game *game);

//CLOSE GAME
int		ft_close_game(t_game *game);

//ERROR
void	ft_free_all_memory(t_game *game);
void	ft_error(char *str, t_game *game);
void	ft_free_map(t_game *game);
void	ft_destroy_img(t_game *game);

//UTILS
int		ft_strlen_v2(const char *s);
void	ft_check_chars(t_game *game);
void	ft_is_valid_items(t_game *game);
void	ft_put_map(char **map);
int		get_height_map(char **map);
void	is_empty_line(t_game *game, char **map);

//GET_NEXT_LINE
char	*get_next_line(int fd);
#endif
