/*
** debug_bis.c for tetris in /home/VEYSSI_B/rendu/Programmation_Shell/PSU_2015_tetris/src
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sun Mar 20 19:59:38 2016 Baptiste veyssiere
** Last update Sun Mar 20 20:07:44 2016 Baptiste veyssiere
*/

#include "tetris.h"

void	print_tetri(t_tetrimino *tetri)
{
  my_putstr("Tetriminos : Name ");
  my_putstr(tetri->name);
  if (tetri->error)
    {
      my_putstr(" : Error\n");
      return ;
    }
  my_putstr(" : Size ");
  my_put_nbr(tetri->width);
  my_putchar('*');
  my_put_nbr(tetri->height);
  my_putstr(" : Color ");
  my_put_nbr(tetri->color);
  print_form(tetri);
}

void	print_tetrinbr(t_tetrimino *tetri)
{
  int   x;

  x = 0;
  while (tetri != NULL)
    {
      ++x;
      tetri = tetri->next;
    }
  my_putstr("Tetriminos : ");
  my_put_nbr(x);
  my_putchar('\n');
}

void	term_init(struct termios *term)
{
  term->c_lflag &= ~(ECHO | ICANON);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
}

void			debug_part(t_config *config, t_tetrimino **tetri)
{
  struct termios        term;
  struct termios        copy;
  char                  buf[4];
  void                  *save;

  if (!(config->debug))
    return ;
  ioctl(0, TCGETS, &term);
  copy = term;
  term_init(&term);
  ioctl(0, TCSETS, &term);
  sort_list(tetri);
  print_keys(config);
  print_tetrinbr(*tetri);
  save = *tetri;
  while (*tetri != NULL)
    {
      print_tetri(*tetri);
      *tetri = (*tetri)->next;
    }
  *tetri = save;
  my_putstr("Press a key to start Tetris\n");
  read(0, buf, 3);
  ioctl(0, TCSETS, &copy);
  return ;
}
