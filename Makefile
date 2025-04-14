

NAME = so_long

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -O3

MLX_DIR = mlx_linux
LIBFT_DIR = libft
SRC_DIR = src
GNL_DIR = gnl

SRCS = $(wildcard $(SRC_DIR)/*.c)
# $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_A = $(GNL_DIR)/gnl.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -lz
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -I/usr/include

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(GNL_A):
	make -C $(GNL_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re