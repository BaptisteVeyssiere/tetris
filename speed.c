/*
** speed.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar 17 14:33:45 2016 nathan scutari
** Last update Thu Mar 17 15:01:17 2016 nathan scutari
*/

#include "tetris.h"

int	get_speed(int speed, int level)
{
  int	x;
  double	sspeed;

  sspeed = speed;
  x = 0;
  while (++x < level)
    sspeed -= (sspeed / 20);
  return ((int)sspeed);
}
