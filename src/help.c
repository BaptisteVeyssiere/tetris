/*
** help.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Mar 17 01:58:41 2016 nathan scutari
** Last update Fri Mar 18 21:19:33 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	display_help(char *str)
{
  my_putstr("Usage: ");
  my_putstr(str);
  my_putstr(" [options]\n");
  my_putstr("Options:\n  ");
  my_putstr("--help                 Display this help\n  ");
  my_putstr("-l --level={num}       Start Tetris at level num\n  ");
  my_putstr("-kl --key-left={K}     Move tetrimino on LEFT with key K\n  ");
  my_putstr("-kr --key-right={K}    Move tetrimino on RIGHT with key K\n  ");
  my_putstr("-kt --key-turn={K}     Turn tetrimino with key K\n  ");
  my_putstr("-kd --key-drop={K}     Set default DROP on key K\n  ");
  my_putstr("-kq --key-quit={K}     Quit program when press key K\n  ");
  my_putstr("-kp --key-pause={K}    Pause and restart game when press key ");
  my_putstr("K\n  ");
  my_putstr("--map-size={row,col}   Set game size at row, col\n  ");
  my_putstr("-w --without-next      Hide next tetrimino\n  ");
  my_putstr("-d --debug             Debug mode\n");
}
