# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2023/10/24 21:31:26 by ngenadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2023/05/29 14:04:21 by ngenadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

include .color_code.txt

CC			= @clang -g3 -MMD

RM 			= @rm -rf

PATH_MLX	= ./mlx/

LINUX		= -I /usr/include -L /usr/lib/ -lmlx -L mlx -I mlx -lXext -l X11 -lm -lz

LIBMLX		=	libmlx.a

CFLAGS 		= #-Wall -Wextra -Werror -g3 #-fsanitize=address

LIBMLX	:=	$(addprefix $(PATH_MLX), $(LIBMLX))

SRCS =	srcs/main.c \
		srcs/ray_casting/init.c \
		srcs/ray_casting/move.c \
		srcs/ray_casting/color_image.c \
		srcs/ray_casting/rc_utils.c \
		srcs/ray_casting/niki_cast.c \
		srcs/parsing/parser.c \
		srcs/parsing/check_file.c \
		srcs/parsing/check_flag.c \
		srcs/parsing/check_config.c \
		srcs/parsing/check_map.c \
		srcs/parsing/parser_utils.c \
		srcs/parsing/parser_utils_2.c \
		srcs/reading/gnl.c \
		srcs/reading/read_file.c \
		srcs/reading/gnl_utils.c \
		srcs/utils/lib_1.c \
		srcs/utils/lib_2.c \
		srcs/utils/list.c \
		srcs/utils/ft_split.c \
		srcs/utils/print_error.c \
		srcs/utils/free_utils.c

OBJS = $(SRCS:.c=.o)

DPD				= $(OBJ:.o=.d)

all: $(NAME)

mlx/libmlx.a:
			$(MAKE) -C $(PATH_MLX)

$(NAME): ${OBJS} ${LIBMLX}
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) ${LINUX} -o $(NAME)

%o: %.c
	$(CC) $(cFLAGS) -I /usr/include -Imlx -O3 -o $@ -c $<

-include $(DPD)

clean:
	make -C $(PATH_MLX) clean
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY : all clean fclean re leak debug git
