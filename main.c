/*
** main.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
** 
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
** 
** Started on  Wed Mar  2 18:08:00 2016 nathan scutari
** Last update Thu Mar  3 14:08:13 2016 nathan scutari
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
  srand(time(NULL));
  initscr();
  start_color();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, 1);
  curs_set(0);
  init_pair(1, COLOR_RED, 0);
  init_pair(2, COLOR_GREEN, 0);
  init_pair(3, COLOR_YELLOW, 0);
  init_pair(4, COLOR_BLUE, 0);
  init_pair(5, COLOR_MAGENTA, 0);
  init_pair(6, COLOR_CYAN, 0);
  init_pair(7, COLOR_WHITE, 0);
  
}

int	main()
{
  t_config	config;
  t_tetrimino	*tetri;
  int		key;
  int		c;
  struct winsize	win;

  tetri = NULL;
  c = -1;
  load_tetriminos(&tetri);
  choose_tetrimino(tetri);
  prep_screen();
  init_config(&config, tetri);
  display_game(&config, tetri);
  while (key != 10)
    {
      ioctl(0, TIOCGWINSZ, &win);
      key = getch();
      if (key != ERR)
	key_control(key, &config);
      if (++c == 100)
	{
	  display_game(&config);
	  game_physics(&config, tetri);
	  c = -1;
	}
      usleep(5000);
    }
  endwin();
}
