/*
** display_dec.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 13:28:21 2016 nathan scutari
** Last update Thu Mar  3 13:44:17 2016 nathan scutari
*/

#include "tetris.h"
#include <ncurses.h>
#include <stdlib.h>

void	display_next(t_config *config)
{
  int	x;
  int	y;

  color_set(rand() % 7 + 1, 0);
  mvprintw(3, config->width + 20, "---NEXT---");
  color_set(config->next->color, 0);
  y = -1;
  while (++y < config->next->height)
    {
      x = -1;
      while (++x < config->next->width)
	mvprintw(4 + y, config->width + 20 + 4 -
		 (config->next->width / 2) + x, "%c",
		 config->next->form[y][x]);
    }
  x = -1;
  while (++x < 5)
    {
      color_set(rand() % 7 + 1, 0);
      mvprintw(4 + x, config->width + 20, "|");
      mvprintw(4 + x, config->width + 20 + 9, "|");
    }
  x = -1;
  while (++x < 10)
    {
      color_set(rand() % 7 + 1, 0);
      mvprintw(9, config->width + 20 + x, "-");
    }
}
