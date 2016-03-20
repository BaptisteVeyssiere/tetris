/*
** tetrimino_info.c for check_tetrimino in /home/scutar_n/rendu/PSU/PSU_2015_bstetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Tue Feb 23 15:41:25 2016 nathan scutari
** Last update Sun Mar 20 19:47:23 2016 Baptiste veyssiere
*/

#include "tetris.h"
#include "get_next_line.h"

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
  char	*verify;
  int	x;
  int	y;

  y = -1;
  if ((*form = get_form_wordtab(width, height)) == NULL)
    return (-1);
  while (++y < height)
    if (((*form)[y] = get_next_line(fd)) == NULL)
      return (-1);
  y = -1;
  x = -1;
  if ((verify = get_next_line(fd)) != NULL)
    while (verify[++x])
      if (verify[x] == '*')
	return (-1);
  if (verify_lines(*form, height, width) == -1)
    return (-1);
  if (verify_columns(*form, height, width) == -1)
    return (-1);
  return (0);
}
