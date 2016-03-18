/*
** tetri_rotation.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 16:03:22 2016 nathan scutari
** Last update Thu Mar  3 18:19:06 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>

void	free_and_replace(t_config *config, char **new_tetri)
{
  int	x;
  int	tmp;

  x = -1;
  while (++x < config->form->height)
    free(config->form->form[x]);
  free(config->form->form);
  config->form->form = new_tetri;
  tmp = config->form->width;
  config->form->width = config->form->height;
  config->form->height = tmp;
}

void	rotation_tetri(t_config *config, char **new_tetri)
{
  int	x;
  int	y;

  y = -1;
  while (++y < config->form->height)
    {
      x = - 1;
      while (++x < config->form->width)
	new_tetri[x][y] = config->form->form[config->form->height - 1 - y]
	  [x];
    }
}

int	turn_tetri(t_config *config)
{
  char	**new_tetri;
  int	x;
  int	y;

  if ((new_tetri = malloc(sizeof(char *) * config->form->width + 1)) == NULL)
    return (-1);
  x = -1;
  while (++x < config->form->width)
    {
      if ((new_tetri[x] = malloc(config->form->height + 1)) == NULL)
	return (-1);
      new_tetri[x][config->form->height] = 0;
    }
  new_tetri[config->form->width] = 0;
  y = -1;
  rotation_tetri(config, new_tetri);
  free_and_replace(config, new_tetri);
  display_game(config, 1);
}
