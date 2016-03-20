/*
** check_tetriminos.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris/src
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Sun Mar 20 13:06:25 2016 nathan scutari
** Last update Sun Mar 20 13:21:45 2016 nathan scutari
*/

#include "tetris.h"

int	verify_lines(char **form, int height, int width)
{
  int	y;
  int	x;
  int	only_space;

  y = -1;
  while (++y < height)
    {
      x = -1;
      only_space = 1;
      while (++x < width)
	if (form[y][x] == '*')
	  only_space = 0;
      x -= 1;
      while (form[y][++x])
	if (form[y][x] == '*')
	  return (-1);
      if (only_space)
	return (-1);
    }
  return (0);
}

int	verify_columns(char **form, int height, int width)
{
  int	y;
  int	x;
  int	only_space;

  x = -1;
  while (++x < width)
    {
      y = -1;
      only_space = 1;
      while (++y < height)
	if (form[y][x] == '*')
	  only_space = 0;
      if (only_space)
	return (-1);
    }
  return (0);
}
