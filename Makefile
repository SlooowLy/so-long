NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRC = check_map.c ft_exit.c ft_itoa.c ft_split.c ft_strncmp.c key_hook.c key_hook_utils.c key_hook_utils_2.c printf_d.c readmap.c so_long.c so_long_utils.c so_long_utils_2.c

BONUS = itoa_bonus.c map_bonus.c ft_exit_bonus.c ft_split_bonus.c ft_strncmp_bonus.c key_hook_bonus.c key_hook_utils_bonus.c key_hook_utils_2_bonus.c readmap_bonus.c so_long_bonus.c so_long_utils_bonus.c so_long_utils_2_bonus.c

OBJS = $(SRC:.c=.o)
OBJBS = $(BONUS:.c=.o)

%.o: %.c lib.h
	$(CC) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o so_long
bonus: $(OBJBS) $(OBJS) lib_bonus.h
	$(CC) $(FLAGS) $(OBJBS) -o so_long_bonus
	$(CC) $(FLAGS) $(OBJS) -o so_long

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(OBJS) $(OBJBS)
	rm -f $(NAME)
	rm -f so_long_bonus

re: fclean all
