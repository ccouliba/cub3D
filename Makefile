# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2023/09/01 19:21:20 by ccouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include .color_code.txt

NAME		= cub3D

CC			= clang

RM 			= rm -rf

PATH_MLX	= ./mlx/

LINUX		= -I /usr/include -L /usr/lib/ -lmlx -L mlx -I mlx -lXext -l X11 -lm -lz

LIBMLX		=	libmlx.a

CFLAGS 		= -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBMLX	:=	$(addprefix $(PATH_MLX), $(LIBMLX))

SRCS =	srcs/main.c \
		srcs/reading/gnl.c \
		srcs/reading/read_file.c \
		srcs/reading/gnl_utils.c \
		srcs/parsing/check_file.c \
		srcs/parsing/check_flag.c \
		srcs/parsing/check_config.c \
		srcs/parsing/check_map.c \
		srcs/parsing/parser.c \
		srcs/parsing/parser_utils.c \
		srcs/parsing/parser_utils_2.c \
		srcs/parsing/parser_utils_3.c \
		srcs/raycasting/color_image.c \
		srcs/raycasting/niki_cast.c \
		srcs/raycasting/rc_utils.c \
		utils/lib_1.c \
		utils/lib_2.c \
		utils/list.c \
		utils/ft_split.c \
		utils/print_error.c \
		utils/free_utils.c

OBJS = $(SRCS:.c=.o)

DEP = $(SRCS:.c=.d)
 
DIR_OBJ = .objects

BUG_REPORT = .bug.txt
# a = $(shell echo abc)

# CHECK_INPUT = echo "make: [$(_RED)!$(_END)] Do you want to continue [Y/n]?" && read input && sleep 1.5 ; if [ $$input = "n" ]; then echo "make: aborting ..." && exit 1 ; fi

all: $(NAME)

mlx/libmlx.a:
			$(MAKE) -C $(PATH_MLX)

$(NAME): ${OBJS} ${LIBMLX}
		make -C $(PATH_MLX) all
		if [ ! -d "$(DIR_OBJ)" ]; then mkdir "$(DIR_OBJ)"; fi
		echo "\t\t[$(_BLUE)all$(_END)] [$(_BLUE)clean$(_END)] [$(_BLUE)fclean$(_END)] [$(_BLUE)re$(_END)] [$(_BLUE)leak$(_END)] [$(_BLUE)gitp$(_END)]"
		for i in $(SRCS); do printf "make: $(_BLUE)all$(_END):processing sources... :" ; printf "\\t$$i\\r" ; sleep 0.3 ; printf "\033[0K\r" ; done
		$(CC) $(CFLAGS) $(OBJS) ${LINUX} -o $(NAME)
		echo "make: $(_BLUE)all$(_END): Compilation ...\t\t\t\t[ $(_GREEN)DONE$(_END) ]"
		mv *.o ./$(DIR_OBJ)/
# 		@bash .script_bar.sh
		echo "make: $(_BLUE)all$(_END): Exec creation ...\t\t\t\t[ $(_GREEN)DONE$(_END) ]"
		echo "make: $(_BLUE)all$(_END): Exec name :\t\t\t\t\t[$(_YELLOW)$(NAME)$(_END)]"

%o: %.c
	$(CC) $(cFLAGS) -I /usr/include -Imlx -O3 -o $@ -c $<

clean:
	make -C $(PATH_MLX) clean
	${RM} $(DIR_OBJ)/$(OBJS)
	for i in $(DIR_OBJ)/$(OBJS) ; do printf "make: $(_BLUE)clean$(_END): removing objects... :" ; printf "\\t$$i\\r" ; sleep 0.4 ; printf "\033[0K\r" ; done
	echo "make: $(_BLUE)clean$(_END): Removing object files ...\t\t\t[ $(_GREEN)DONE$(_END) ]\n"

fclean: clean
	${RM} $(NAME)
	if [ -d "$(DIR_OBJ)" ]; then $(RM) "$(DIR_OBJ)"; fi
	echo "make: $(_BLUE)fclean$(_END): Removing repertory : .objects ...\t\t[ $(_GREEN)DONE$(_END) ]"
	echo "make: $(_BLUE)fclean$(_END): Removing the executable ...\t\t[ $(_GREEN)DONE$(_END) ]\n"
#if [ -f "$(BUG_REPORT)" ]; then rm -f "$(BUG_REPORT)" ; echo "[$(_RED)!$(_END)] Removing scan report file ...\t\t\t[ $(_GREEN)DONE$(_END) ]"; fi

re: fclean all

# No usefull for this project
leak: re
	echo "\t\t\t$(_BG_CYAN)LEAK FEATURE$(_END)"
	echo "\t\t\t(valgrind)\n"
	echo "make: $(_BLUE)leak$(_END): Lauching [$(_YELLOW)$(NAME)$(_END)] with valgrind ...\n"
	echo "make: $(_BLUE)leak$(_END): Choose a map (.cub)"
	read -p "filepath:> " filepath || ([ -f "filepath" ] && valgrind --leak-check=full --suppressions=.leaks.txt ./$(NAME) filepath || echo "make: valgrind:> file does not exist or is invalid.")
# if [ $$?  ]

gitp: fclean
	echo "\t\t\t$(_BG_CYAN)GITP FEATURES$(_END)\n"
	git add . 
	echo "make: $(_BLUE)gitp$(_END): Adding files ...\t\t\t\t[ $(_GREEN)DONE$(_END) ]"
	echo "make: $(_BLUE)gitp$(_END): Committing ...\t\t\t\t[$(_BK_RED)FAILED$(_END)]"
	echo "make: $(_BLUE)gitp$(_END): Need a name to commit."
	echo -n "make: [$(_RED)!$(_END)] " ; read -p "gitp:> " var ; echo "make: [$(_GREEN)!$(_END)] $(_BLUE)gitp$(_END): You will commit with this comment : \`$$var'" ; git commit -m $$var
	echo "make: $(_BLUE)gitp$(_END): Committing ...\t\t\t\t[ $(_GREEN)DONE$(_END) ]\n"
	git push
	echo "make: $(_BLUE)gitp$(_END): Pushing ...\t\t\t\t\t[ $(_GREEN)DONE$(_END) ]"
	bash .script_bar.sh
	echo "make: $(_BLUE)gitp$(_END): Local repository is up to date. Ready to $(_U_WHITE)pull$(_END) or $(_U_WHITE)merge$(_END)."

debug : fclean
	echo "\t\t\t\t$(_BG_CYAN)BUGS SCAN$(_END)"
	if [ -f "$(BUG_REPORT)" ]; then $(RM) "$(BUG_REPORT)"; fi
	scan-build-12 make -j > $(BUG_REPORT) | grep "scan-build:" || ([ $$? -eq 0 ] && echo -e "$(_BLUE)debug$(_END): scan report saved in file : `$(BUG_REPORT)'" || echo -e make: $(_BLUE)debug$(_END): Debug scan failed.

# .INIT : <commande à exécuter au début du make>
.INIT:

# .DEFAULT : <commande à exécuter en cas d'erreur >
.DEFAULT : if [ $$? -eq 0 ]; then echo "make: $(_RED)FAIL$(_END)"

# .DONE : <commande exécuter à la fin de make>
.DONE : if [ -f "$(BUG_REPORT)" ]; then $(RM) "$(BUG_REPORT)"; fi

# .IGNORE: Evite au make de s'arrêter en cas d'erreur
.IGNORE :

# .SILENT: N'affiche pas les commandes exécutées
.SILENT:

# .PRECIOUS: <fichier>* Ne pas détruit pas les fichiers ..
.PRECIOUS:

# Test if a cmd worked
# $(COMP) $(SRC) -o $(NAME) $(LDFLAGS) $(CFLAGS) || ([ $$? -eq 0 ] && echo -e "\033[31mCompilation success!\033[0m" || echo -e "\033[32mCompilation ABORTEDed!\033[0m")

# .PHONY : <cible>* Déclares les cibles qui ne sont pas des fichiers
.PHONY : all clean fclean re leak gitp #debug
