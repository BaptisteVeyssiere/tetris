/*
** user_config.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sat Mar  5 13:34:52 2016 nathan scutari
** Last update Sun Mar 20 19:48:01 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	get_control_config(char *arg, t_config *config, int i)
{
  if (arg == 0)
    return (-1);
  if (i == 1)
    {
      config->left = arg;
      ++config->doublon.left;
    }
  else if (i == 2)
    {
      config->right = arg;
      ++config->doublon.right;
    }
  else if (i == 3)
    {
      config->turn = arg;
      ++config->doublon.turn;
    }
  else if (i == 4)
    {
      config->drop = arg;
      ++config->doublon.drop;
    }
  return (0);
}

int	get_other_config(char *arg, t_config *config, int i)
{
  if (arg == 0)
    return (-1);
  if (i == 5)
    {
      config->quit = arg;
      ++config->doublon.quit;
    }
  else if (i == 6)
    {
      config->pause = arg;
      ++config->doublon.pause;
    }
  else if (i == 0)
    if ((config->level = my_getnbr(arg)) == -1)
      return (-1);
  return (0);
}

int	get_wd(t_config *config, int i)
{
  if (i == 7)
    {
      config->hide = 1;
      ++config->doublon.hide;
    }
  else if (i == 8)
    {
      config->debug = 1;
      ++config->doublon.debug;
    }
  return (0);
}

int	get_next_config(char **av, int x, t_config *config)
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

int	user_config(char **av, t_config *config)
{
  int	x;
  int	args;
  int	ac;

  ac = -1;
  while (av[++ac] != NULL);
  init_doublon(&config->doublon);
  x = 0;
  while (++x < ac)
    {
      if ((args = get_next_config(av, x, config)) == -1)
	return (-1);
      x += args;
    }
  if (config->doublon.turn > 1 || config->doublon.drop > 1 ||
      config->doublon.right > 1 || config->doublon.left > 1 ||
      config->doublon.pause > 1 || config->doublon.quit > 1 ||
      config->doublon.hide > 1 || config->doublon.debug > 1 ||
      config->doublon.help > 1 ||
      (config->left != NULL && config->left[0] == 0) ||
      (config->right != NULL && config->right[0] == 0) ||
      (config->drop != NULL && config->drop[0] == 0) ||
      (config->turn != NULL && config->turn[0] == 0))
    return (-1);
  return (0);
}
