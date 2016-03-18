/*
** debug.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Thu Mar 17 00:54:16 2016 nathan scutari
** Last update Fri Mar 18 16:55:30 2016 nathan scutari
*/

#include "tetris.h"
#include <termios.h>
#include <sys/ioctl.h>

void	my_debugstr(char *str)
{
  int	x;

  x = -1;
  while (str[++x])
    {
      if (str[x] == 27)
	my_putstr("^E");
      else if (str[x] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[x]);
    }
  my_putchar('\n');
}

void	print_keys(t_config *config)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  my_debugstr(config->left);
  my_putstr("Key Right : ");
  my_debugstr(config->right);
  my_putstr("Key Turn : ");
  my_debugstr(config->turn);
  my_putstr("Key Drop : ");
  my_debugstr(config->drop);
  my_putstr("Key Quit : ");
  my_debugstr(config->quit);
  my_putstr("Key Pause : ");
  my_debugstr(config->pause);
  my_putstr("Next : ");
  if (config->hide)
    my_putstr("No\n");
  else
    my_putstr("Yes\n");
  my_putstr("Level : ");
  my_put_nbr(config->level);
  my_putstr("\nSize : ");
  my_put_nbr(config->height);
  my_putchar('*');
  my_put_nbr(config->width);
  my_putchar('\n');
}

void			debug_part(t_config *config, t_tetrimino *tetri)
{
  struct termios	term;
  struct termios	copy;
  char			buf[2];

  ioctl(0, TCGETS, &term);
  copy = term;
  term.c_lflag &= ~(ECHO | ICANON);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  ioctl(0, TCSETS, &term);
  //sort_list(&tetri);
  print_keys(config);
  read(0, buf, 1);
  ioctl(0, TCSETS, &copy);
  return ;
}
