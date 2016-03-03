##
## Makefile for check_tetrimino in /home/scutar_n/rendu/PSU/PSU_2015_bstetris
##
## Made by nathan scutari
## Login   <scutar_n@epitech.net>
##
## Started on  Tue Feb 23 16:56:01 2016 nathan scutari
## Last update Thu Mar  3 14:07:37 2016 nathan scutari
##

NAME	=	check_tetrimino

SRCS	=	main.c			\
		my_getnbr.c		\
		form_wordtab.c		\
		tools.c			\
		load_tetrimino.c	\
		init_config.c		\
		game_physic.c		\
		key_control.c		\
		display_dec.c		\
		my_put_nbr.c		\
		tetrimino_info.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-lncurses

CFLAGS	=	-I.

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
