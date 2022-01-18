NAME = so_long

CC = gcc


FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

BONUS = itoa_bonus.c map_bonus.c ft_exit_bonus.c ft_split_bonus.c ft_strncmp_bonus.c key_hook_bonus.c key_hook_utils_bonus.c key_hook_utils_2_bonus.c readmap_bonus.c so_long_bonus.c so_long_utils_bonus.c so_long_utils_2_bonus.c

OBJS = $(SRC:.c=.o)
OBJBS = $(BONUS:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o so_long

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(OBJS) $(OBJBS)
	rm -f $(NAME)

re: fclean all
