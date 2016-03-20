/*
** fill_key.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar 10 22:52:37 2016 nathan scutari
** Last update Sun Mar 20 19:44:14 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	fill_key(char **str, char *end)
{
  int	x;

  x = -1;
  (*str) = malloc(my_strlen(end) + 1);
  while (end[++x])
    (*str)[x] = end[x];
  (*str)[x] = 0;
}

void	get_entry(char *key)
{
  int	x;

  x = -1;
  while (++x < 10)
    key[x] = 0;
  x = -1;
  while (read(0, &key[++x], 1) != -1 && x < 9);
}

int	compare_key(char *entry, char *key)
{
  int	x;

  x = -1;
  while (key[++x] && key[x] == entry[x]);
  if (entry[x] == 0 && key[x] == 0)
    return (1);
  return (0);
}
