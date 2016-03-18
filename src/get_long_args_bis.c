/*
** get_long_args_bis.c for tetris in /home/VEYSSI_B/rendu/Programmation_Shell/PSU_2015_tetris
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Mar 18 16:07:22 2016 Baptiste veyssiere
** Last update Fri Mar 18 16:08:53 2016 Baptiste veyssiere
*/

#include <tetris.h>

char	**get_long_compare_table()
{
  char  **compare;

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
