# ================== VARIABLES ==================
SRC_DIR		= sources
OBJ_DIR		= obj

SRC			= $(SRC_DIR)/flood_fill.c \
			  $(SRC_DIR)/ft_check_map.c \
			  $(SRC_DIR)/ft_close_game.c \
			  $(SRC_DIR)/ft_display_map.c \
			  $(SRC_DIR)/ft_free_error.c \
			  $(SRC_DIR)/ft_handle_input.c \
			  $(SRC_DIR)/ft_init_game.c \
			  $(SRC_DIR)/ft_init_map.c \
			  $(SRC_DIR)/ft_set_pos.c \
			  $(SRC_DIR)/get_next_line.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/so_long.c

OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Libft et MiniLibX
LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= ./minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a

# Nom de l'exécutable
NAME		= so_long

# Flags pour linker MiniLibX sous Linux
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Couleurs
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RESET		= \033[0m

# ================== REGLES ==================
all: $(LIBFT) $(MLX_LIB) $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@printf "$(YELLOW)[Compiling]$(RESET) Linking objects...   \r"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)[Success]$(RESET) Compilation successfully! 🎉\n"

# Compilation des fichiers .o dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(YELLOW)[Compiling]$(RESET) $<                    \r"
	@$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj si inexistant
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation de la Libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compilation de MiniLibX
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Nettoyage des fichiers objets
clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf "$(YELLOW)[Cleaned]$(RESET) Objects removed.\n"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "$(YELLOW)[Cleaned]$(RESET) Binary removed.\n"

# Recompile tout
re: fclean all

.PHONY: all clean fclean re
