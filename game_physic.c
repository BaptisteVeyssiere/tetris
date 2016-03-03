/*
** game_physic.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 10:55:39 2016 nathan scutari
** Last update Thu Mar  3 14:02:16 2016 nathan scutari
*/

#include "tetris.h"

int	gravity_ok(t_config *config)
{
  int	x;
  int	y;

  x = -1;
  if (config->pos[1] + config->form->height - 1 >=
      config->height - 1)
    return (0);
  while (++x < config->form->width)
    {
      y = config->form->height;
      while (config->form->form[--y][x] != '*');
      if (config->map[y + config->pos[1] + 1][x + config->pos[0]] > 0)
	return (0);
    }
  return (1);
}

void	moving_in_non_movings(t_config *config)
{
  int	x;
  int	y;

  y = -1;
  while (++y < config->form->height)
    {
      x = -1;
      while (++x < config->form->width)
	if (config->form->form[y][x] == '*')
	  config->map[y + config->pos[1]]
	    [x + config->pos[0]] = config->form->color;
    }
}

void	new_form(t_config *config, t_tetrimino *tetri)
{
  moving_in_non_movings(config);
  config->form = config->next;
  config->pos[1] = 0;
  config->pos[0] = ((config->width / 2) -
			 (config->form->width / 2));
  config->next = choose_tetrimino(tetri);
}

void	game_physics(t_config *config, t_tetrimino *tetri)
{
  if (gravity_ok(config))
    config->pos[1]++;
  else
    new_form(config, tetri);
}
