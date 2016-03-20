/*
** display_dec.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar  3 13:28:21 2016 nathan scutari
** Last update Sun Mar 20 19:43:49 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	bottom_and_stats(t_config *config)
{
  int	x;

  x = -1;
  if (config->hide == 0)
    while (++x < 10)
      mvprintw(9, config->width + 20 + x, "-");
  color_set(7, 0);
  mvprintw(10, config->width + 20, "LEVEL -> %d", config->level);
  mvprintw(12, config->width + 20, "HIGHSCORE -> %d", config->highscore);
  mvprintw(14, config->width + 20, "SCORE -> %d", config->score);
  mvprintw(16, config->width + 20, "NEXT LEVEL IN -> %d LINES",
	   10 - (int)config->lines);
  config->played += time(NULL) - config->time;
  config->time = time(NULL);
  mvprintw(18, config->width + 20, "TIME PLAYED -> %d:%d",
  	   (config->played) / 60, (config->played) % 60);
}

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
  color_set(7, 0);
  while (++x < 5)
    {
      mvprintw(4 + x, config->width + 20, "|");
      mvprintw(4 + x, config->width + 20 + 9, "|");
    }
}
