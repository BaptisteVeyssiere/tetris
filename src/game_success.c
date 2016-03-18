/*
** game_success.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 14:44:34 2016 nathan scutari
** Last update Fri Mar 18 17:21:57 2016 nathan scutari
*/

#include "tetris.h"

void	line_complete(t_config *config, int y)
{
  int	x;

  x = -1;
  display_game(config, 0);
  while (++x < config->width)
    config->map[y][x] = 0;
  display_game(config, 0);
  while (y > 0)
    {
      x = -1;
      while (++x < config->width)
	config->map[y][x] = config->map[y - 1][x];
      y--;
    }
  config->lines++;
  config->combo++;
  if (config->lines == 10)
    {
      config->lines = 0;
      config->level++;
      config->speed -= (config->speed / 8);
    }
  usleep(300000);
  display_game(config, 0);
}

int	game_finished(t_config *config)
{
  int	x;
  int	y;

  x = -1;
  while (++x < config->form->width)
    {
      y = -1;
      while (++y < config->form->height)
	if (config->form->form[y][x] == '*' &&
	    config->map[y][config->pos[0] + x] > 0)
	  return (1);
    }
  return (0);
}

void	is_line_complete(t_config *config)
{
  int	y;
  int	x;
  int	same;

  y = -1;
  while (++y < config->height)
    {
      x = -1;
      same = 1;
      while (++x < config->width)
	if (config->map[y][x] == 0)
	  same = 0;
      if (same == 1)
	line_complete(config, y);
    }
}
