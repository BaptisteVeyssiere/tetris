/*
** form_wordtab.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 11:50:58 2016 nathan scutari
** Last update Sun Mar 20 19:44:22 2016 Baptiste veyssiere
*/

#include "tetris.h"

char	**get_form_wordtab(int width, int height)
{
  int	y;
  char	**form;

  y = -1;
  if ((form = malloc(sizeof(char *) * (height + 1))) == NULL)
    return (NULL);
  while (++y < height)
    {
      if ((form[y] = malloc(width + 1)) == NULL)
	return (NULL);
      form[y][width] = 0;
    }
  form[y] = NULL;
  return (form);
}

int		tetri_in_list(t_tetrimino **tetr)
{
  t_tetrimino	*elem;

  if ((elem = malloc(sizeof(t_tetrimino))) == NULL)
    return (-1);
  elem->next = *tetr;
  *tetr = elem;
  elem->error = 0;
  elem->width = 0;
  elem->height = 0;
  elem->form = NULL;
  return (0);
}

void	my_fillstr(char *str, char *to_fill)
{
  int	x;

  x = -1;
  while (to_fill[++x] != 0)
    str[x] = to_fill[x];
  str[x] = 0;
}

int	is_tetrimino(char *str)
{
  int	x;
  int	y;
  char	compare[10];

  x = -1;
  y = -1;
  my_fillstr(compare, "tetrimino");
  while (str[++x]);
  while (x >= 0 && str[--x] != '.');
  if (x == 0)
    return (0);
  while (str[++x])
    if (str[x] != compare[++y])
      return (0);
  return (1);
}

char	*get_fullname(char *file)
{
  char	*fullname;
  int	x;

  x = -1;
  if ((fullname = malloc(my_strlen(file) + 12)) == NULL)
    return (NULL);
  my_fillstr(fullname, "tetriminos/");
  while (file[++x])
    fullname[x + 11] = file[x];
  fullname[x + 11] = 0;
  return (fullname);
}
