/*
** debug.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar 17 00:54:16 2016 nathan scutari
** Last update Sun Mar 20 20:03:12 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	my_debugstr(char *str)
{
  int	x;

  x = -1;
  while (str[++x])
    {
      if (str[x] == 27)
	my_putstr("^E");
      else if (str[x] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[x]);
    }
  my_putchar('\n');
}

void	print_keys(t_config *config)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  my_debugstr(config->left);
  my_putstr("Key Right : ");
  my_debugstr(config->right);
  my_putstr("Key Turn : ");
  my_debugstr(config->turn);
  my_putstr("Key Drop : ");
  my_debugstr(config->drop);
  my_putstr("Key Quit : ");
  my_debugstr(config->quit);
  my_putstr("Key Pause : ");
  my_debugstr(config->pause);
  my_putstr("Next : ");
  if (config->hide)
    my_putstr("No\n");
  else
    my_putstr("Yes\n");
  my_putstr("Level : ");
  my_put_nbr(config->level);
  my_putstr("\nSize : ");
  my_put_nbr(config->height);
  my_putchar('*');
  my_put_nbr(config->width);
  my_putchar('\n');
}

void	free_errtetri(t_tetrimino *tetri)
{
  free(tetri->name);
  free(tetri);
}

void		clean_list(t_tetrimino **tetri)
{
  t_tetrimino	*tmp;
  t_tetrimino	*previous;

  sort_error_list(tetri);
  tmp = *tetri;
  previous = NULL;
  while (tmp != NULL && tmp->error == 0)
    {
      previous = tmp;
      tmp = tmp->next;
    }
  if (tmp != NULL)
    {
      tmp = previous->next;
      previous->next = NULL;
      while (tmp != NULL)
	{
	  previous = tmp->next;
	  free_errtetri(tmp);
	  tmp = previous;
	}
    }
}

void	print_form(t_tetrimino *tetri)
{
  int	x;
  int	y;
  int	pos;

  my_putstr(" :\n");
  y = -1;
  while (tetri->form[++y])
    {
      pos = my_strlen(tetri->form[y]);
      while (tetri->form[y][--pos] == ' ');
      x = -1;
      while (++x <= pos)
	my_putchar(tetri->form[y][x]);
      my_putchar('\n');
    }
}
