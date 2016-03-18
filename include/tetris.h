/*
** tetris.h for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 14:16:12 2016 nathan scutari
** Last update Fri Mar 18 17:17:46 2016 nathan scutari
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_tetrimino
{
  int			width;
  int			height;
  int			color;
  char			error;
  char			*name;
  char			**form;
  struct s_tetrimino	*next;
}			t_tetrimino;

typedef struct		s_config
{
  char			*right;
  char			*left;
  int			level;
  int			played;
  char			lines;
  int			speed;
  int			score;
  int			highscore;
  char			combo;
  char			debug;
  char			*turn;
  char			*drop;
  char			*pause;
  char			brek;
  char			*quit;
  char			hide;
  int			time;
  int			width;
  int			height;
  int			pos[2];
  char			**map;
  t_tetrimino		*form;
  t_tetrimino		*next;
}			t_config;

char		**get_form_wordtab(int, int);
char		*my_realloc(char , char *);
char		*get_fullname(char *);
t_tetrimino	*choose_tetrimino(t_tetrimino *);
char		*get_next_line(int);
char		*get_term(char**);
char		**get_short_compare_table();
char		**get_long_compare_table();

#endif /* !TETRIS_H_ */
