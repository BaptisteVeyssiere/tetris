/*
** my_getnbr.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 07:57:29 2015 nathan scutari
** Last update Sun Mar 20 19:25:50 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	is_overflow(char *tab, int length)
{
  int	i;
  char	max_int[] = "2147483647";

  i = 0;
  if (length > 10)
    return (1);
  if (length < 10)
    return (0);
  while (tab[i] != 0)
    {
      if (tab[i] > max_int[i])
	return (1);
      i++;
    }
  return (0);
}

int	syntax_check(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] < '0' || str[i] > '9')
      return (1);
  return (0);
}

int       	my_getnbr(char *str)
{
  int		i;
  int		dec;
  unsigned int	nbr;

  if (str == 0)
    return (-1);
  i = my_strlen(str);
  if (syntax_check(str))
    return (-1);
  if (is_overflow(str, i))
    return (-1);
  dec = 1;
  nbr = 0;
  while (--i >= 0)
    {
      nbr += (str[i] - 48) * dec;
      dec *= 10;
    }
  return (nbr);
}
