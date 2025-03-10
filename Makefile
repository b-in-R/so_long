

NAME = so_long

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -O3 #-Werror

MLX_DIR = mlx_linux
LIBFT_DIR = libft

SRCS = so_long.c ft_put_img.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -lz
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR) -I/usr/include

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re