NAME		=	cub3D
MLX			=	libmlx.a

SRCS			=	cub3d.c \
					utils/*.c \
					parse/*.c \
					GNL/*.c \
					display/*.c 

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

RMRF		=	rm -rf

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME):
			@ $(MAKE) -C mlx all
			@ cp ./mlx/$(MLX) .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME), Linux)
$(NAME):
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(SRCS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
endif

all:		$(NAME)

ifeq ($(UNAME), Darwin)
clean:
			@ $(MAKE) -C mlx clean
			@ $(RMRF) Cub3D.dSYM
endif

ifeq ($(UNAME), Linux)
clean:
			@ $(MAKE) -C mlx_linux clean
			@ $(RMRF) Cub3D.dSYM
endif

fclean:		clean
			@ $(RM) $(MLX)
			@ $(RM) cub3D

re:			fclean all

.PHONY:		$(NAME) all test clean fclean re

