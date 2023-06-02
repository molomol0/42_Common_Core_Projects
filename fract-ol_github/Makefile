NAME := fractol

CC := cc
CFLAGS := -Wall -Werror-Wextra  -g3 -I./include
MLX_PATH := ./mlx_linux

SRCS := main.c

OBJS := $(SRCS:.c=.o)

MLX_FLAGS := -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all