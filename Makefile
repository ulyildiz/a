NAME = fractol
CC = cc -Wall -Wextra -Werror
SRC = calculate_set.c \
		check.c \
		draw.c \
		fractol.c \
		free_error.c \
		hook.c \
		utils.c 
SRCB = calculate_set_bonus.c \
		check_bonus.c \
		draw_bonus.c \
		fractol_bonus.c \
		free_error_bonus.c \
		hook_bonus.c \
		utils_bonus.c 
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

$(NAME): $(OBJ)
	@make -C mlx/
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
all: $(NAME)

bonus: $(OBJB)
	@make -C mlx/
	$(CC) $(OBJB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) -c -o $@ $<

clean:
	@make -C mlx/ clean
	@rm -rf *.o
fclean: clean
	@rm -rf $(MLX_LIB)
	@rm -rf $(NAME)
re: fclean all

.PHONY: re fclean clean all