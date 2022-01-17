CC = cc

NAME = so_long.a

FLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC_FILES = check_map.c check_map.c check_map.c ft_split.c ft_strncmp.c key_hook_utils_2.c key_hook_utils.c key_hook.c printf_d.c readmap.c so_long_utils_2.c so_long_utils.c so_long.c \

SRCB_FILES = ft_exit.c ft_split.c ft_strncmp.c how_is_map.c itoa.c key_hook_utils_2.c key_hook_utils.c key_hook.c map.c readmap.c so_long_utils.c so_long_utils.c so_long.c \

SRC = $(addprefix ./so_long/, $(SRC_FILES))
SRCB = $(addprefix ./so_long_bonus/, $(SRCB_FILES))

OBJS = $(SRC:.c=.o)
OBJBS = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJBS) $(MLX_LIB) $(FT_LIB)
	ar rc $(NAME) $(OBJBS)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX_LIB) $(MLX) -lz -o solong

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(NAME)
	rm -f so_long
	rm -f $(OBJS) $(OBJBS)

re: fclean all
