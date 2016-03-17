/*
** init_config.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Wed Mar  2 22:52:10 2016 nathan scutari
** Last update Thu Mar 17 02:41:50 2016 nathan scutari
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

void	init_config(t_config *config, t_tetrimino *tetri)
{
  int	x;
  int	y;

  x = -1;
  fill_key(&config->right, "\033[C");
  fill_key(&config->left, "\033[D");
  fill_key(&config->turn, "\033[A");
  fill_key(&config->drop, "\033[B");
  fill_key(&config->pause, " ");
  fill_key(&config->quit, "\033");
  config->played = 0;
  config->brek = 0;
  config->highscore = 0;
  config->score = 0;
  config->debug = 0;
  config->hide = 0;
  config->level = 1;
  config->lines = 0;
  config->time = time(NULL);
  config->form = choose_tetrimino(tetri);
  config->next = choose_tetrimino(tetri);
  config->height = 20;
  config->width = 10;
  config->map = malloc(sizeof(char *) * config->height);
  config->pos[0] = (config->width / 2) - (config->form->width / 2);
  config->pos[1] = 0;
  while (++x < config->height)
    config->map[x] = malloc(config->width);
  x = -1;
  while (++x < config->height)
    {
      y = -1;
      while (++y < config->width)
	config->map[x][y] = 0;
    }
}
