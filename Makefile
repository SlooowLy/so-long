NAME = so_long

CC = gcc


FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRC = src/check_map.c src/ft_exit.c src/ft_itoa.c src/ft_split.c src/ft_strncmp.c src/key_hook.c src/key_hook_utils.c src/key_hook_utils_2.c src/printf_d.c src/readmap.c src/so_long.c src/so_long_utils.c src/so_long_utils_2.c

BONUS = itoa.c map.c ft_exit.c ft_split.c ft_strncmp.c key_hook.c key_hook_utils.c key_hook_utils_2.c readmap.c so_long.c so_long_utils.c so_long_utils_2.c

SRCB = $(addprefix ./bonus/, $(BONUS))

OBJS = $(SRC:.c=.o)
OBJS = $(SRCB:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o so_long

bonus: $(OBJBS)
	$(CC) $(FLAGS) $(OBJBS) -o yo

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(OBJS) $(OBJBS)
	rm -f $(NAME)

re: fclean all
