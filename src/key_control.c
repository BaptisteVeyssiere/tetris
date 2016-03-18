/*
** key_control.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar  3 14:03:33 2016 nathan scutari
** Last update Fri Mar 18 17:59:48 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	right_move(t_config *config)
{
  int	y;
  int	x;

  y = -1;
  if (config->pos[0] + 1 + config->form->width >
      config->width)
    return ;
  while (++y < config->form->height)
    {
      x = config->form->width;
      while (config->form->form[y][--x] != '*');
      if (config->map[y + config->pos[1]]
	  [x + config->pos[0] + 1] > 0)
	return ;
    }
  config->pos[0]++;
  display_game(config, 1);
}

void	left_move(t_config *config)
{
  int	x;
  int	y;

  y = -1;
  if (config->pos[0] - 1 < 0)
    return ;
  while (++y < config->form->height)
    {
      x = -1;
      while (config->form->form[y][++x] != '*');
      if (config->map[y + config->pos[1]]
	  [x + config->pos[0] - 1] > 0)
	return ;
    }
  config->pos[0]--;
  display_game(config, 1);
}

void	is_movement_key(char *key, t_config *config, t_tetrimino *tetri)
{
  if (compare_key(key, config->right))
    right_move(config);
  else if (compare_key(key, config->left))
    left_move(config);
  else if (compare_key(key, config->drop))
    drop_tetri(config, 0, tetri);
  else if (compare_key(key, config->turn))
    turn_tetri(config);
}

void	key_control(char *key, t_config *config, t_tetrimino *tetri)
{
  if (config->brek == 0)
    is_movement_key(key, config, tetri);
  if (compare_key(key, config->pause))
    {
      config->brek = (config->brek + 1) % 2;
      config->time = time(0);
    }
}
