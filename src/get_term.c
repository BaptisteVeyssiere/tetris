/*
** get_term.c for tetris in /home/VEYSSI_B/rendu/Programmation_Shell/PSU_2015_tetris
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Mar 18 16:10:47 2016 Baptiste veyssiere
** Last update Sun Mar 20 19:40:27 2016 Baptiste veyssiere
*/

#include <tetris.h>

char	*get_term(char **env)
{
  char  *model;
  int   i;

  model = "TERM=";
  i = -1;
  while (env[++i] && !compare_largs(env[i], model));
  if (!env[i])
    return (NULL);
  return (&env[i][5]);
}

void	init_config_values(t_config *config)
{
  int	x;

  x = -1;
  config->played = 0;
  config->speed = 5000;
  config->brek = 0;
  config->highscore = 0;
  config->combo = 0;
  config->score = 0;
  config->debug = 0;
  config->hide = 0;
  config->level = 1;
  config->lines = 0;
  config->time = time(NULL);
  config->height = 20;
  config->width = 10;
  config->map = malloc(sizeof(char *) * config->height);
  config->pos[1] = 0;
  while (++x < config->height)
    config->map[x] = malloc(config->width);
}
