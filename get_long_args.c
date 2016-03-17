/*
** get_long_args.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar 17 01:19:39 2016 nathan scutari
** Last update Thu Mar 17 02:07:29 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>

char	**get_long_compare_table()
{
  char	**compare;

  compare = malloc(sizeof(char *) * 12);
  fill_compare(&compare[0], "--help");
  fill_compare(&compare[1], "--level=");
  fill_compare(&compare[2], "--key-left=");
  fill_compare(&compare[3], "--key-right=");
  fill_compare(&compare[4], "--key-turn=");
  fill_compare(&compare[5], "--key-drop=");
  fill_compare(&compare[6], "--key-quit=");
  fill_compare(&compare[7], "--key-pause=");
  fill_compare(&compare[8], "--map-size=");
  fill_compare(&compare[9], "--without_next");
  fill_compare(&compare[10], "--debug");
  compare[11] = 0;
  return (compare);
}

int	config_print(int i, t_config *config)
{
  if (i == 0)
    {
      display_help();
      return (-1);
    }
  else if (i == 9)
    config->hide = 1;
  else if (i == 10)
    config->debug = 1;
  return (0);
}

int	config_nbrs(int i, t_config *config, char *str)
{
  if (i == 1)
    if ((config->level = my_getnbr(&str[8])) == -1)
      return (-1);
  return (0);
}

int	config_controls(int i, t_config *config, char *str)
{
  if (i == 2)
    config->left = &str[11];
  else if (i == 3)
    config->right = &str[12];
  else if (i == 4)
    config->turn = &str[11];
  else if (i == 5)
    config->drop = &str[11];
  return (0);
}

int	config_pandq(int i, t_config *config, char *str)
{
  if (i == 6)
    config->quit = &str[11];
  else if (i == 7)
    config->pause = &str[12];
  return (0);
}

int	compare_largs(char *arg, char *compare)
{
  int	x;

  x = -1;
  while (compare[++x] && arg[x] == compare[x]);
  if (compare[x] == 0)
    return (1);
  return (0);
}

int	get_next_long_config(char **av, int x, t_config *config)
{
  int	i;
  char	**compare;

  i = -1;
  compare = get_long_compare_table();
  while (compare[++i] && compare_largs(av[x], compare[i]) == 0);
  if (i == 0 || i == 9 || i == 10)
    return (config_print(i, config));
  else if (i == 1 || i == 8)
    return (config_nbrs(i, config, av[x]));
  else if (i >= 2 && i <= 5)
    return (config_controls(i, config, av[x]));
  else if (i == 6 || i == 7)
    return (config_pandq(i, config, av[x]));
  return (-1);
}
