/*
** sort_list.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 17:17:35 2016 Baptiste veyssiere
** Last update Fri Mar 18 16:27:16 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>

void		sort_list(t_tetrimino **list)
{
  t_tetrimino	*tmp;
  t_tetrimino	*previous;

  tmp = *list;
  previous = NULL;
  while (tmp->next != NULL)
    {
      if (compare_size(tmp, tmp->next))
	{
	  swap_list(previous, tmp, tmp->next, list);
	  previous = NULL;
	  tmp = *list;
	}
      else
	{
	  previous = tmp;
	  tmp = tmp->next;
	}
    }
}

int		compare_size(t_tetrimino *current, t_tetrimino *next)
{
  int	x;

  x = -1;
  while (current->name[++x] && next->name[x] && current->name[x] ==
	 next->name[x]);
  if (current->name[x] > next->name[x])
    return (1);
  return (0);
}

void		swap_list(t_tetrimino *previous, t_tetrimino *current,
			  t_tetrimino *next, t_tetrimino **list)
{
  t_tetrimino	*tmp;

  if (previous == NULL)
    *list = next;
  else
    previous->next = next;
  tmp = next->next;
  next->next = current;
  current->next = tmp;
}
