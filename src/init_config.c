/*
** init_config.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 22:52:10 2016 nathan scutari
** Last update Sun Mar 20 19:45:35 2016 Baptiste veyssiere
*/

#include "tetris.h"

t_tetrimino	*choose_tetrimino(t_tetrimino *tetri)
{
  int	tetriminos_nbr;
  int	chosen_one;
  void	*save;

  save = tetri;
  tetriminos_nbr = 0;
  while (tetri != NULL)
    {
      tetriminos_nbr++;
      tetri = tetri->next;
    }
  tetri = save;
  chosen_one = (rand() % tetriminos_nbr);
  while (--chosen_one > 0)
    tetri = tetri->next;
  return (tetri);
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

int	init_config(t_config *config)
{
  int	x;
  int	y;

  config->drop = NULL;
  config->left = NULL;
  config->right = NULL;
  config->turn = NULL;
  fill_key(&config->pause, " ");
  fill_key(&config->quit, "q");
  init_config_values(config);
  x = -1;
  while (++x < config->height)
    {
      y = -1;
      while (++y < config->width)
	config->map[x][y] = 0;
    }
  return (0);
}
