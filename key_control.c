/*
** key_control.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 14:03:33 2016 nathan scutari
** Last update Thu Mar  3 14:11:23 2016 nathan scutari
*/

#include "tetris.h"

void	right_move(t_config *config)
{
  if (config->pos[0] + 1 + config->form->width >=
      config->width)
    return ;
    config->pos[0]++;
  display_game(config);
}

void	left_move(t_config *config)
{
  if (config->pos[0] - 1 <= 0)
    config->pos[0]--;
  return ;
  display_game(config);
}

void	is_movement_key(int key, t_config *config)
{
  if (key == config->right)
    right_move(config);
  else if (key == config->left)
    left_move(config);
}

void	key_control(int key, t_config *config)
{
  is_movement_key(key, config);
}
