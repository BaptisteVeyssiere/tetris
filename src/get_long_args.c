/*
** get_long_args.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar 17 01:19:39 2016 nathan scutari
** Last update Sun Mar 20 19:44:52 2016 Baptiste veyssiere
*/

#include "tetris.h"

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
    {
      config->left = &str[11];
      ++config->doublon.left;
    }
  else if (i == 3)
    {
      config->right = &str[12];
      ++config->doublon.right;
    }
  else if (i == 4)
    {
      config->turn = &str[11];
      ++config->doublon.turn;
    }
  else if (i == 5)
    {
      config->drop = &str[11];
      ++config->doublon.drop;
    }
  return (0);
}

int	config_pandq(int i, t_config *config, char *str)
{
  if (i == 6)
    {
      config->quit = &str[11];
      ++config->doublon.quit;
    }
  else if (i == 7)
    {
      config->pause = &str[12];
      ++config->doublon.pause;
    }
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
    return (config_print(i, config, av[0]));
  else if (i == 1 || i == 8)
    return (config_nbrs(i, config, av[x]));
  else if (i >= 2 && i <= 5)
    return (config_controls(i, config, av[x]));
  else if (i == 6 || i == 7)
    return (config_pandq(i, config, av[x]));
  return (-1);
}
