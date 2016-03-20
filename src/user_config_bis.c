/*
** user_config_bis.c for tetris in /home/VEYSSI_B/rendu/Programmation_Shell/PSU_2015_tetris
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Mar 18 16:45:31 2016 Baptiste veyssiere
** Last update Sun Mar 20 19:31:06 2016 Baptiste veyssiere
*/

#include <tetris.h>

void	fill_compare(char **str, char *fill)
{
  int   x;

  x = -1;
  *str = malloc(my_strlen(fill) + 1);
  while (fill[++x])
    (*str)[x] = fill[x];
  (*str)[x] = 0;
}

char	**get_short_compare_table()
{
  char  **compare;

  compare = malloc(sizeof(char *) * 10);
  fill_compare(&compare[0], "-l");
  fill_compare(&compare[1], "-kl");
  fill_compare(&compare[2], "-kr");
  fill_compare(&compare[3], "-kt");
  fill_compare(&compare[4], "-kd");
  fill_compare(&compare[5], "-kq");
  fill_compare(&compare[6], "-kp");
  fill_compare(&compare[7], "-w");
  fill_compare(&compare[8], "-d");
  compare[9] = 0;
  return (compare);
}

int	compare_args(char *arg, char *compare)
{
  int   x;

  x = -1;
  while (compare[++x] && arg[x] == compare[x]);
  if (arg[x] == 0 && compare[x] == 0)
    return (1);
  return (0);
}

void	init_doublon(t_doublon *doublon)
{
  doublon->turn = 0;
  doublon->drop = 0;
  doublon->right = 0;
  doublon->left = 0;
  doublon->pause = 0;
  doublon->quit = 0;
  doublon->help = 0;
  doublon->hide = 0;
  doublon->debug = 0;
}
