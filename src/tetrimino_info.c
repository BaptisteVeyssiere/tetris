/*
** tetrimino_info.c for check_tetrimino in /home/scutar_n/rendu/PSU/PSU_2015_bstetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Tue Feb 23 15:41:25 2016 nathan scutari
** Last update Wed Mar  2 16:59:09 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>

int	get_width(int fd)
{
  char	buffer[2];
  char	*entry;
  int	ret;
  int	width;

  buffer[0] = 0;
  entry = NULL;
  while ((ret = read(fd, buffer, 1)) && buffer[0] >= '0' &&
	 buffer[0] <= '9')
    entry = my_realloc(buffer[0], entry);
  if (ret == 0 || (width = my_getnbr(entry)) == -1 || buffer[0] != ' '
      || width == 0)
    return (-1);
  free(entry);
  return (width);
}

int	get_height(int fd)
{
  char	buffer[2];
  char	*entry;
  int	ret;
  int	height;

  buffer[0] = 0;
  entry = NULL;
  while ((ret = read(fd, buffer, 1)) && buffer[0] >= '0' &&
	 buffer[0] <= '9')
    entry = my_realloc(buffer[0], entry);
  if (ret == 0 || (height = my_getnbr(entry)) == -1 || buffer[0] != ' '
      || height == 0)
    return (-1);
  free(entry);
  return (height);
}

int	get_color(int fd)
{
  char	buffer[2];
  char	*entry;
  int	ret;
  int	color;

  buffer[0] = 0;
  entry = NULL;
  while ((ret = read(fd, buffer, 1)) && buffer[0] >= '0' &&
	 buffer[0] <= '9')
    entry = my_realloc(buffer[0], entry);
  if (ret == 0 || (color = my_getnbr(entry)) == -1 || buffer[0] != '\n' ||
      color < 0 || color > 7)
    return (-1);
  free(entry);
  return (color);
}

int	check_form(int fd, int width, int height, char ***form)
{
  char	buffer[2];
  int	ret;
  int	x;
  int	y;

  x = -1;
  if ((*form = get_form_wordtab(width, height)) == NULL)
    return (-1);
  while (++x < height)
    {
      y = -1;
      while (++y < width)
	{
	  ret = read(fd, buffer, 1);
	  if ((buffer[0] != '*' && buffer[0] != ' ') || ret == 0)
	    return (-1);
	  (*form)[x][y] = buffer[0];
	}
      if ((x != height - 1 && read(fd, buffer, 1) && buffer[0] != '\n'))
	return (-1);
    }
  if ((read(fd, buffer, 1) != 0 && buffer[0] != '\n') ||
      read(fd, buffer, 1) != 0)
    return (-1);
  return (0);
}
