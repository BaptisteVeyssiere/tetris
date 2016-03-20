/*
** main.c for check_tetrimino in /home/scutar_n/rendu/PSU/PSU_2015_bstetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Tue Feb 23 15:29:35 2016 nathan scutari
** Last update Sun Mar 20 19:55:57 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	print_info(int width, int height, int color, char *file)
{
  int	x;

  x = my_strlen(file) - 1;
  while (file[--x] != '/' && x >= 0);
  my_putstr("Tetriminos : Name ");
  while (file[++x] && file[x] != '.')
    my_putchar(file[x]);
  my_putstr(" : Size ");
  my_put_nbr(width);
  my_putchar('*');
  my_put_nbr(height);
  my_putstr(" : Color ");
  my_put_nbr(color);
  my_putstr(" :\n");
}

int	display_error(char *file)
{
  int	x;

  x = my_strlen(file) - 1;
  while (file[--x] != '/' && x >= 0);
  my_putstr("Tetriminos : Name ");
  while (file[++x] && file[x] != '.')
    my_putchar(file[x]);
  my_putstr(" : Error\n");
  return (-1);
}

char	*get_name(char *str)
{
  char	*name;

  int	x;
  x = -1;
  while (str[++x] != '.');
  if ((name = malloc(x + 1)) == NULL)
    return (NULL);
  x = -1;
  while (str[++x] != '.')
    name[x] = str[x];
  name[x] = 0;
  return (name);
}

int	get_tetrimino_info(int fd, char *file, t_tetrimino **tetr)
{
  int	width;
  int	height;
  int	color;
  char	**form;

  form = NULL;
  if (tetri_in_list(tetr) == -1)
    return (-1);
  if ((width = get_width(fd)) == -1 ||
      (height = get_height(fd)) == -1 ||
      (color = get_color(fd)) == -1 ||
      check_form(fd, width, height, &form) == -1)
    (*tetr)->error = 1;
  else
    {
      (*tetr)->width = width;
      (*tetr)->height = height;
      (*tetr)->form = form;
      (*tetr)->color = color;
      (*tetr)->error = 0;
    }
  (*tetr)->name = get_name(file);
  return (0);
}

int		load_tetriminos(t_tetrimino **tetri)
{
  DIR		*dir;
  struct dirent	*file;
  int		fd;
  char		*fullname;
  int		counter;

  if ((counter = 0) == 0 && (dir = opendir("./tetriminos")) == NULL)
    return (my_perror("Error : can not open tetriminos directory\n"));
  while ((file = readdir(dir)) != NULL)
    if (file->d_name[0] != '.' && is_tetrimino(file->d_name))
      {
	fullname = get_fullname(file->d_name);
	if ((fd = open(fullname, O_RDONLY)) == -1)
	  return (-1);
	free(fullname);
	if (get_tetrimino_info(fd, file->d_name, tetri) == -1)
	  return (-1);
	if ((*tetri)->error == 0)
	  ++counter;
	close(fd);
      }
  if (counter == 0)
    return (my_perror("No tetrimino detected\n"));
  closedir(dir);
  return (0);
}
