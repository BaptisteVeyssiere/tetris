/*
** get_next_line_beta.c for get_next_line in /home/scutar_n/rendu/CPE_2015_getnextline
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Jan 15 14:42:53 2016 nathan scutari
** Last update Sun Mar 20 19:28:15 2016 Baptiste veyssiere
*/

#include "get_next_line.h"

int		verify_buffer(char *buffer, int *offset, char **line)
{
  int	x;

  x = -1;
  if (buffer[0] == 0)
    return (0);
  --(*offset);
  if (((*line) = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (1);
  while (buffer[++(*offset)] != '\n' && buffer[*offset] != 0)
    (*line)[++x] = buffer[*offset];
  (*line)[++x] = 0;
  if (buffer[*offset] == 0)
    {
      x = -1;
      while (++x < READ_SIZE)
	buffer[x] = 0;
      *offset = 0;
      return (0);
    }
  ++(*offset);
  return (1);
}

char		*concat_line(char *line, char *buff)
{
  int	x;
  int	y;
  char	*newline;

  x = -1;
  y = -1;
  if (line != NULL)
    {
      newline = line;
      while (line[++x] != 0);
      if ((line = malloc(sizeof(char) * (READ_SIZE + x + 1))) == NULL)
	return (NULL);
      x = -1;
      while (newline[++x] != 0)
	line[x] = newline[x];
      x -= 1;
      free(newline);
    }
  else
    if ((line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
      return (NULL);
  while (buff[++y] != 0 && buff[y] != '\n')
    line[++x] = buff[y];
  line[++x] = 0;
  return (line);
}

int	check_lines(char *buff)
{
  int	x;

  x = -1;
  while (buff[++x] != 0)
    if (buff[x] == '\n')
      return (1);
  return (0);
}

void	complete_buffer(char *buff, char *buffer)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  while (buff[++x] != '\n');
  while (buff[++x] != 0)
    buffer[++y] = buff[x];
  buffer[++y] = 0;
}

char		*get_next_line(int fd)
{
  char		*line;
  char		buff[READ_SIZE + 1] = {0};
  static char	buffer[READ_SIZE + 1] = {0};
  static int	offset = 0;
  int		ret;

  line = NULL;
  if (verify_buffer(buffer, &offset, &line) == 1)
    return (line);
  while ((ret = read(fd, buff, READ_SIZE)))
    {
      if (ret == -1)
	return (NULL);
      buff[ret] = 0;
      if ((line = concat_line(line, buff)) == NULL)
	return (NULL);
      if (check_lines(buff))
	{
	  complete_buffer(buff, buffer);
	  return (line);
	}
      if (ret < READ_SIZE)
	return (line);
    }
  return (line);
}
