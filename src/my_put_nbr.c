/*
** my_put_nbr.c for my_put_nbr in /home/scutar_n/rendu/Piscine_C_J12
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Nov 25 14:09:32 2015 nathan scutari
** Last update Sun Mar 20 19:39:04 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	my_put_nbr(int nbr)
{
  if (nbr == -2147483648)
    {
      write(1, "-2147483648", 11);
      return (0);
    }
  if (nbr < 0)
    {
      nbr = -nbr;
      write(1, "-", 1);
    }
  if (nbr >= 10)
    my_put_nbr(nbr / 10);
  nbr = nbr % 10 + 48;
  write(1, &nbr, 1);
  return (0);
}
