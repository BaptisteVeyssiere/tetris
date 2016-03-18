##
## Makefile for check_tetrimino in /home/scutar_n/rendu/PSU/PSU_2015_bstetris
##
## Made by nathan scutari
## Login   <scutar_n@epitech.net>
##
## Started on  Tue Feb 23 16:56:01 2016 nathan scutari
## Last update Fri Mar 18 16:52:32 2016 Baptiste veyssiere
##

NAME	=	tetris

SRCS	=	src/main.c		\
		src/my_getnbr.c		\
		src/speed.c		\
		src/user_config.c	\
		src/get_long_args.c	\
		src/form_wordtab.c	\
		src/help.c		\
		src/debug.c		\
		src/tools.c		\
		src/load_tetrimino.c	\
		src/init_config.c	\
		src/tetri_rotation.c	\
		src/game_physic.c	\
		src/end_game.c		\
		src/fill_key.c		\
		src/game_success.c	\
		src/drop_bomb.c		\
		src/key_control.c	\
		src/display_dec.c	\
		src/my_put_nbr.c	\
		src/tetrimino_info.c	\
		src/get_long_args_bis.c	\
		src/get_term.c		\
		src/user_config_bis.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-lncurses

CFLAGS	=	-I./include

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
