/*
** drop_tetri.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar  3 14:32:40 2016 nathan scutari
** Last update Thu Mar 17 02:28:10 2016 nathan scutari
*/

#include "tetris.h"

void	drop_tetri(t_config *config, int bricolage, t_tetrimino *tetri)
{
  if (gravity_ok(config))
    {
      config->pos[1]++;
      config->score += 2;
      drop_tetri(config, ++bricolage, tetri);
    }
  if (bricolage == 1)
    display_game(config, 1);
}
