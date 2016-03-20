/*
** tools.c for allum1 in /home/scutar_n/rendu/CPE/CPE_2015_Allum1
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Thu Feb 11 21:13:21 2016 nathan scutari
** Last update Sun Mar 20 19:36:38 2016 Baptiste veyssiere
*/

#include "tetris.h"

char	*my_realloc(char add, char *prompt)
{
  int	x;
  char	*newprompt;

  x = -1;
  if (prompt == NULL)
    {
      prompt = malloc(2);
      prompt[0] = add;
      prompt[1] = 0;
      return (prompt);
    }
  newprompt = malloc(sizeof(char) * (my_strlen(prompt) + 2));
  while (prompt[++x] != 0)
    newprompt[x] = prompt[x];
  newprompt[x] = add;
  newprompt[++x] = 0;
  free(prompt);
  return (newprompt);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	x;

  x = -1;
  while (str[++x])
    write(1, &str[x], 1);
}

int	my_strlen(char *str)
{
  int	x;

  x = -1;
  while (str[++x]);
  return (x);
}

int	my_perror(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}
