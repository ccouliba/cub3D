# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2023/04/04 15:13:37 by ngenadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

include .color_code.txt

CC			= @clang

RM 			= @rm -rf

PATH_MLX	= ./mlx/

LINUX		= -I /usr/include -L /usr/lib/ -lmlx -L mlx -I mlx -lXext -l X11 -lm -lz

LIBMLX		=	libmlx.a

CFLAGS 		= -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBMLX	:=	$(addprefix $(PATH_MLX), $(LIBMLX))

SRCS =	srcs/main.c \
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
		srcs/ray_casting/raycasting.c \
		utils/lib_1.c \
		utils/lib_2.c \
		utils/list.c \
		utils/ft_split.c \
		utils/print_error.c \
		utils/free_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

mlx/libmlx.a:
			$(MAKE) -C $(PATH_MLX)

$(NAME): ${OBJS} ${LIBMLX}
		make -C $(PATH_MLX) all
		@echo "[$(_BLUE)!$(_END)] Rules :\t[$(_BLUE)all$(_END)] [$(_BLUE)clean$(_END)] [$(_BLUE)fclean$(_END)] [$(_BLUE)re$(_END)] [$(_BLUE)leak$(_END)] [$(_BLUE)debug$(_END)]"
		@echo -n "\n"
		$(CC) $(CFLAGS) $(OBJS) ${LINUX} -o $(NAME)
		@echo "[$(_GREEN)!$(_END)] Compilation ... 	  [$(_GREEN)SUCCESS$(_END)]"
		@echo "[$(_GREEN)!$(_END)] Creating .out ... 	  [$(_GREEN)SUCCESS$(_END)]"
		@bash .script_bar.sh
		@echo "[$(_YELLOW)!$(_END)] Exec name :\t\t  [$(_YELLOW)$(NAME)$(_END)]"

%o: %.c
	$(CC) $(cFLAGS) -I /usr/include -Imlx -O3 -o $@ -c $<

clean:
	make -C $(PATH_MLX) clean
	${RM} $(OBJS)
	@echo "[$(_RED)!$(_END)] Removing objects ...  [$(_GREEN)SUCCESS$(_END)]"

fclean: clean
	${RM} $(NAME)
	@echo "[$(_RED)!$(_END)] Removing .out ...	  [$(_GREEN)SUCCESS$(_END)]"

re: fclean all

leak: re
	@echo "Choose a map (.cub)"
	@echo -n "> "
	@read ${path_file}
	@echo "\t\t\t\t\t$(_BG_CYAN)LEAK TEST$(_END) (valgrind)"
	@valgrind --suppressions=.leaks.txt ./$(NAME) ${path_file}

debug : fclean
	@echo "\t\t\t\t\t$(_BG_CYAN)BUGS SCAN$(_END)"
	@scan-build-12 make -j | grep "scan-build:"

gitt: fclean
	@echo "\n"
	@echo "\t\t\t\t\t$(_BG_CYAN)GIT FEATURES$(_END)\n"
	git add . 
	@echo "[$(_GREEN)!$(_END)] Adding files ... 	  [$(_GREEN)SUCCESS$(_END)]"
	@echo "[$(_RED)!$(_END)] Committing ... 	  [$(_BK_RED)  FAIL $(_END)]"
	@read -p "--> Need a name to commit (one word)&> " var
	git commit -m var
	@echo "[$(_GREEN)!$(_END)] Committing ... 	  [$(_GREEN)SUCCESS$(_END)]\n"
	git push
	@echo "[$(_GREEN)!$(_END)] Pushing :		    [$(_GREEN)SUCCESS$(_END)]\n"
	@bash .script_bar.sh
	@echo "--> Repo up to pull or merge"

.PHONY : all clean fclean re leak debug git
