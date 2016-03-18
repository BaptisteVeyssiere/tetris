/*
** init_config.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 22:52:10 2016 nathan scutari
** Last update Fri Mar 18 16:26:25 2016 Baptiste veyssiere
*/

#include "tetris.h"
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <curses.h>

t_tetrimino	*choose_tetrimino(t_tetrimino *tetri)
{
  int	tetriminos_nbr;
  int	chosen_one;
  void	*save;

  save = tetri;
  tetriminos_nbr = 0;
  while (tetri != NULL)
    {
      if (tetri->error == 0)
	tetriminos_nbr++;
      tetri = tetri->next;
    }
  tetri = save;
  chosen_one = (rand() % tetriminos_nbr) + 1;
  while (chosen_one > 0)
    {
      if (tetri->error == 0)
	--chosen_one;
      if (chosen_one == 0)
	return (tetri);
      tetri = tetri->next;
    }
  return (NULL);
}

void	display_non_movings(t_config *config)
{
  int	x;
  int	y;

  y = -1;
  while (++y < config->height)
    {
      x = -1;
      while (++x < config->width)
	{
	  if (config->map[y][x] > 0)
	    {
	      color_set((int)config->map[y][x], 0);
	      mvprintw(y + 1, x + 16, "*");
	    }
	}
    }
}

void	display_moving(t_config *config)
{
  int	x;
  int	y;

  y = -1;
  while (++y < config->form->height)
    {
      x = -1;
      while (++x < config->form->width)
	{
	  color_set(config->form->color, 0);
	  if (config->form->form[y][x] == '*')
	    mvprintw(config->pos[1] + y + 1, config->pos[0] + x + 16, "%c",
		     config->form->form[y][x]);
	}
    }
}

void	display_game(t_config *config, int form)
{
  int	x;

  x = -1;
  color_set(7, 0);
  clear();
  while (++x < config->width + 2)
    {
      mvprintw(0, 15 + x, "-");
      mvprintw(config->height + 1, 15 + x, "-");
    }
  x = -1;
  while (++x < config->height)
    {
      mvprintw(1 + x, 15, "|");
      mvprintw(1 + x, 15 + config->width + 1, "|");
    }
  display_non_movings(config);
  if (form == 1)
    display_moving(config);
  if (config->hide == 0)
    display_next(config);
  bottom_and_stats(config);
  refresh();
}

int	init_config(t_config *config, t_tetrimino *tetri, char **env)
{
  int	x;
  int	y;
  int	i;
  char	*s;

  if (setupterm(get_term(env), 1, &i) == 1)
    return (-1);
  if ((s = tigetstr("smkx")) == NULL)
    return (-1);
  write(1, s, my_strlen(s));
  config->drop = tigetstr("kcud1");
  config->left = tigetstr("kcub1");
  config->right = tigetstr("kcuf1");
  config->turn = tigetstr("kcuu1");
  fill_key(&config->pause, " ");
  fill_key(&config->quit, "q");
  init_config_values(config, tetri);
  x = -1;
  while (++x < config->height)
    {
      y = -1;
      while (++y < config->width)
	config->map[x][y] = 0;
    }
}