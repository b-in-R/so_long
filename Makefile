

NAME = so_long

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -O3 #-Werror

MLX_DIR = mlx_linux
LIBFT_DIR = libft
SRC_DIR = src
GNL_DIR = gnl

SRCS = $(wildcard $(SRC_DIR)/*.c)
# $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -lz
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
GNL_FLAGS = -L$(GNL_DIR) -gnl
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -I/usr/include

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(GNL_DIR)/gnl.a
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(GNL_FLAGS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(GNL_DIR)/gnl.a:
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