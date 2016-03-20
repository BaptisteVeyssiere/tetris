/*
** tetri_rotation.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar  3 16:03:22 2016 nathan scutari
** Last update Sun Mar 20 19:47:37 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	rotation_ok(t_config *config, char **new_tetri)
{
  int	x;
  int	y;

  if ((config->pos[0] + (config->form->height - 1)) >= config->width)
    return (0);
  else if ((config->pos[1] + (config->form->width - 1)) >= config->height)
    return (0);

  y = -1;
  while (++y < config->form->width)
    {
      x = -1;
      while (++x < config->form->height)
	if (new_tetri[y][x] == '*' && config->map[y + config->pos[1]]
	    [x + config->pos[0]] > 0)
	  return (0);
    }
  return (1);
}

void	free_and_replace(t_config *config, char **new_tetri)
{
  int	x;
  int	tmp;

  x = -1;
  if (rotation_ok(config, new_tetri))
    {
      while (++x < config->form->height)
	free(config->form->form[x]);
      free(config->form->form);
      config->form->form = new_tetri;
      tmp = config->form->width;
      config->form->width = config->form->height;
      config->form->height = tmp;
    }
  else
    {
      while (++x < config->form->height)
	free(new_tetri[x]);
      free(new_tetri);
    }
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
  rotation_tetri(config, new_tetri);
  free_and_replace(config, new_tetri);
  display_game(config, 1);
  return (0);
}
