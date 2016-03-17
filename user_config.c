/*
** user_config.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Sat Mar  5 13:34:52 2016 nathan scutari
** Last update Thu Mar 17 01:57:49 2016 nathan scutari
*/

#include "tetris.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_compare(char **str, char *fill)
{
  int	x;

  x = -1;
  *str = malloc(my_strlen(fill) + 1);
  while (fill[++x])
    (*str)[x] = fill[x];
  (*str)[x] = 0;
}

char 	**get_short_compare_table()
{
  char	**compare;

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
  int	x;

  x = -1;
  while (compare[++x] && arg[x] == compare[x]);
  if (arg[x] == 0 && compare[x] == 0)
    return (1);
  return (0);
}

int	get_control_config(char *arg, t_config *config, int i)
{
  int	key;

  if (arg == 0)
    return (-1);
  if (i == 1)
    config->left = arg;
  else if (i == 2)
    config->right = arg;
  else if (i == 3)
    config->turn = arg;
  else if (i == 4)
    config->drop = arg;
  return (0);
}

int	get_other_config(char *arg, t_config *config, int i)
{
  if (arg == 0)
    return (-1);
  if (i == 5)
    config->quit = arg;
  else if (i == 6)
    config->drop = arg;
  else if (i == 0)
    if ((config->level = my_getnbr(arg)) == -1)
      return (-1);
  return (0);
}

int	get_wd(t_config *config, int i)
{
  if (i == 7)
    config->hide = 1;
  else if (i == 8)
    config->debug = 1;
  return (0);
}

int	get_next_config(int ac, char **av, int x,
			t_config *config)
{
  int	i;
  char	**compare;

  i = -1;
  compare = get_short_compare_table();
  while (compare[++i] && compare_args(av[x], compare[i]) == 0);
  if (i >= 0 && i <= 6)
    {
      if (i >= 1 && i <= 4 && get_control_config(av[x + 1], config, i) == -1)
	return (-1);
      if ((i == 5 || i == 6 || i == 0) &&
	  get_other_config(av[x + 1], config, i) == -1)
	return (-1);
      return (1);
    }
  if (i == 7 || i == 8)
    return (get_wd(config, i));
  return (get_next_long_config(av, x, config));
}

int	user_config(int ac, char **av, t_config *config)
{
  int	x;
  int	args;

  x = 0;
  while (++x < ac)
    {
      if ((args = get_next_config(ac, av, x, config)) == -1)
	return (-1);
      x += args;
    }
  return (0);
}
