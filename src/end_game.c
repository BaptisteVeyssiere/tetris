/*
** end_game.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Mar  4 21:26:10 2016 nathan scutari
** Last update Sun Mar 20 19:44:01 2016 Baptiste veyssiere
*/

#include "tetris.h"

int	save_scores(t_config *config)
{
  char	buf[2];
  int	fd;
  int	highscore;

  clear();
  if ((fd = open("stats/score", O_RDWR)) == -1)
    return (-1);
  read(fd, &highscore, 4);
  while (getch() != -1);
  nodelay(stdscr, 0);
  if (config->score > highscore)
    {
      mvprintw(0, 0, "You beat the previous highscore which was %d !\n",
	       highscore);
      lseek(fd, SEEK_SET, 0);
      write(fd, (char *)&config->score, 4);
    }
  else
    mvprintw(0, 0, "You did not beat the highscore which is %d..Try again !\n",
	     highscore);
  printw("Your score is : %d\nPress any key to quit", config->score);
  read(0, buf, 1);
  return (0);
}

int	end_game(t_config *config, char *key)
{
  int	x;
  int	y;

  y = config->height;
  while (--y >= 0)
    {
      x = -1;
      while (++x < config->width)
	config->map[y][x] = 0;
      usleep(200000);
      display_game(config, 0);
    }
  x = -1;
  while (config->quit[++x])
    key[x] = config->quit[x];
  key[x] = 0;
  save_scores(config);
  return (0);
}

int	get_highscore(t_config *config)
{
  int	fd;

  if ((fd = open("stats/score", O_RDWR)) == -1)
    {
      config->highscore = 0;
      return (0);
    }
  read(fd, &(config->highscore), 4);
  close(fd);
  return (0);
}
