/*
** sort_list.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 17:17:35 2016 Baptiste veyssiere
** Last update Sun Mar 20 19:58:27 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	check_error(t_tetrimino *current, t_tetrimino *next)
{
  if (current->error > next->error)
    return (1);
  return (0);
}

void		sort_error_list(t_tetrimino **list)
{
  t_tetrimino   *tmp;
  t_tetrimino   *previous;

  tmp = *list;
  previous = NULL;
  while (tmp->next != NULL)
    {
      if (check_error(tmp, tmp->next))
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
