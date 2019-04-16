##
## EPITECH PROJECT, 2018
## my runner
## File description:
## Makefile
##
SRC	=	map.c	\
		main.c	\
		rect.c	\
		usage.c	\
		score.c	\
		utils.c	\
		create.c	\
		destroy.c	\
		my_getnbr.c	\
		my_strcpy.c	\
		collision.c	\
		game_loop.c	\
		int_to_str.c	\
		background.c	\
		get_next_line.c	\
		new_obstacles.c	\
		player_movement.c	\
		create_endscreen.c	\
		manage_endscreen.c	\
		manage_main_menu.c	\
		create_main_menu.c	\
		manage_obstacles.c	\
		prepare_game_basis.c	\
		prepare_next_game_phase.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CC	=	gcc

CFLAGS	+=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) -W -Wall -Wextra -Werror $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -lm
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
