# ================== VARIABLES ==================
SRC = flood_fill.c \
	ft_check_map.c \
	ft_close_game.c \
	ft_display_map.c \
	ft_free_error.c \
	ft_handle_input.c \
	ft_init_game.c \
	ft_init_map.c \
	ft_set_pos.c \
	get_next_line.c \
	utils.c \
	so_long.c

OBJS	=	$(SRC:.c=.o)

# Compilation
CC			= 		gcc
CFLAGS		= 		-Wall -Wextra -Werror

# Libft et MiniLibX
LIBFT_DIR	= 		./Libft
LIBFT		= 		$(LIBFT_DIR)/libft.a

MLX_DIR		= 		./minilibx-linux
MLX_LIB		= 		$(MLX_DIR)/libmlx.a

# Nom de l'exécutable
NAME		=		so_long

# Flags pour linker MiniLibX sous Linux
MLX_FLAGS 	= 		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ================== REGLES ==================
all:		$(LIBFT) $(MLX_LIB) $(NAME)

# Compilation de l'exécutable
$(NAME):	$(OBJS) $(LIBFT) $(MLX_LIB)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

# Compilation des fichiers .o
%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

# Compilation de la Libft
$(LIBFT):
			@make -C $(LIBFT_DIR)

# Compilation de MiniLibX
$(MLX_LIB):
			@make -C $(MLX_DIR)

# Nettoyage des fichiers objets
clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_DIR) clean
			@make -C $(MLX_DIR) clean

# Nettoyage complet
fclean:		clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean

# Recompile tout
re:			fclean all

.PHONY:		all clean fclean re
