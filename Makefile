NAME = cub3d
INC = parssing/cub3d.h
LIBFT = ./libft_cub/libft.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf
SRCS = main.c parssing/get_next_line.c parssing/get_next_line_utils.c parssing/direction_addr.c \
		parssing/error_up_map.c parssing/error_up_map1.c parssing/error_up_map2.c \
		parssing/parssing.c parssing/error_redirection.c parssing/error_directions.c \
		cub3d_src/cub3d.c cub3d_src/mlx.c cub3d_src/player.c cub3d_src/player_movement.c \
		cub3d_src/mlx_hook.c cub3d_src/player_mov_II.c cub3d_src/horizontale.c cub3d_src/verticale.c \
		cub3d_src/draw.c cub3d_src/raycast.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^ 

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft_cub

clean:
	$(RM) $(OBJS)
	make -C ./libft_cub clean

fclean : clean
	$(RM) $(NAME)
	make -C ./libft_cub fclean

re : fclean all