# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2023/10/24 20:30:39 by ngenadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= clang -g3

RM 			= rm -rf

PATH_MLX	= ./mlx/

LINUX		= -I /usr/include -L /usr/lib/ -lmlx -L mlx -I mlx -lXext -l X11 -lm -lz

CFLAGS 		= -Wall -Wextra -Werror -MMD

LIBNAME		= libmlx.a

LIBMLX		:=	$(addprefix $(PATH_MLX), $(LIBNAME))

SRCDIR = srcs

OBJDIR = obj

SRC = main.c \
		ray_casting/init.c \
		ray_casting/move.c \
		ray_casting/color_image.c \
		ray_casting/rc_utils.c \
		ray_casting/niki_cast.c \
		parsing/parser.c \
		parsing/check_file.c \
		parsing/check_flag.c \
		parsing/check_config.c \
		parsing/check_map.c \
		parsing/parser_utils.c \
		parsing/parser_utils_2.c \
		reading/gnl.c \
		reading/read_file.c \
		reading/gnl_utils.c \
		utils/lib_1.c \
		utils/lib_2.c \
		utils/list.c \
		utils/ft_split.c \
		utils/print_error.c \
		utils/free_utils.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRCS:%.c=%.o)

DEPFILES := $(SRCS:%.c=%.d)

all: $(NAME)

mlx/libmlx.a:
			@$(MAKE) -C $(PATH_MLX)

$(NAME): $(OBJS) $(LIBMLX) #$(DEPFILES)
	$(CC) $(CFLAGS) $(OBJS) $(LINUX) -o $(NAME)

%.o: %.c 
	$(CC) $(cFLAGS) -I /usr/include -Imlx -O3 -o $@ -c $<

clean:
	make -C $(PATH_MLX) clean
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
