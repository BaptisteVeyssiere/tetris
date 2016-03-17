/*
** main.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Wed Mar  2 18:08:00 2016 nathan scutari
** Last update Thu Mar 17 03:01:22 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>

void	prep_screen()
{
  initscr();
  start_color();
  use_default_colors();
  raw();
  set_escdelay(1);
  noecho();
  curs_set(0);
  init_pair(1, COLOR_RED, 0);
  init_pair(2, COLOR_GREEN, 0);
  init_pair(3, COLOR_YELLOW, 0);
  init_pair(4, COLOR_BLUE, 0);
  init_pair(5, COLOR_MAGENTA, 0);
  init_pair(6, COLOR_CYAN, 0);
  init_pair(7, COLOR_WHITE, 0);
}

int	main(int ac, char **av)
{
  t_config	config;
  t_tetrimino	*tetri;
  char		key[10];
  int		c;
  struct winsize	win;

  srand(time(NULL));
  tetri = NULL;
  c = 0;
  key[0] = 0;
  load_tetriminos(&tetri);
  init_config(&config, tetri);
  if  (user_config(ac, av, &config) == -1)
    {
      endwin();
      return (1);
    }
  if (get_highscore(&config) == -1)
    return (-1);
  prep_screen();
  debug_part(config, tetri);
  nodelay(stdscr, 1);
  display_game(&config, 1);
  while (compare_key(key, config.quit) == 0)
    {
      ioctl(0, TIOCGWINSZ, &win);
      get_entry(key);
      if (key[0] != 0)
	key_control(key, &config, tetri);
      if (++c >= 100 && config.brek == 0)
	{
	  if (game_physics(&config, tetri))
	    end_game(&config, key);
	  c = -1;
	}
      usleep(5000 - (config.level * 100));
    }
    endwin();
}
