CC = cc

NAME = libft_so_long.a

FLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC_FILES = 

SRCB_FILES = 

SRC = $(addprefix ./src/, $(SRC_FILES))
SRCB = $(addprefix ./bonus/, $(SRCB_FILES))

OBJS = $(SRC:.c=.o)
OBJBS = $(SRCB:.c=.o)

LIBFT_PATH = ./utils

LIBX_PATH = ./minilibx

HEADER_DIR = include/
HEADER = include/so_long.h

MLX_LIB = ./minilibx/libmlx.a
FT_LIB = ./utils/libft.a

MAKE = make

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(FT_LIB)
	ar rc $(NAME) $(OBJS)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX_LIB) $(MLX) -lz -o so_long

bonus: $(OBJBS) $(MLX_LIB) $(FT_LIB)
	ar rc $(NAME) $(OBJBS)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX_LIB) $(MLX) -lz -o so_long

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

$(FT_LIB):
	make -C $(LIBFT_PATH)

$(MLX_LIB):
	make -C $(LIBX_PATH)

clean:
	rm -f $(OBJS) $(OBJBS)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(LIBX_PATH)
	

fclean: clean
	rm -f $(NAME)
	rm -f so_long
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all
.PHONY : all clean fclean re bonus
