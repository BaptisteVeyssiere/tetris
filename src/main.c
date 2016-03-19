/*
** main.c for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 18:08:00 2016 nathan scutari
** Last update Sat Mar 19 13:46:17 2016 nathan scutari
*/

#include "tetris.h"
#include <stdlib.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

void			init_ioctl()
{
  struct termios        term;

  if (ioctl(0, TCGETS, &term) != 0)
    printf("ioctl G prob\n");
  term.c_cc[VMIN] = 0;
  if (ioctl(0, TCSETS, &term) != 0)
    printf("ioctl S prob\n");
}

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
  init_ioctl();
}

int	init_sequences(t_config *config, char **env)
{
  int	i;
  char	*s;

  if (setupterm(get_term(env), 1, &i) == 1 || i != 1)
    return (-1);
  if ((s = tigetstr("smkx")) == NULL)
    return (-1);
  write(1, s, my_strlen(s));
  if (config->drop == NULL)
    config->drop = tigetstr("kcud1");
  if (config->left == NULL)
    config->left = tigetstr("kcub1");
  if (config->right == NULL)
    config->right = tigetstr("kcuf1");
  if (config->turn == NULL)
    config->turn = tigetstr("kcuu1");  
}

t_tetrimino	*init_main(char **av, char **env, t_config *config,
			   t_tetrimino *tetri)
{
  if (env[0] == NULL)
    return (NULL);
  srand(time(NULL));
  tetri = NULL;
  if (load_tetriminos(&tetri) == -1 ||
    init_config(config, tetri, env) == -1)
    return (NULL);
  if  (user_config(av, config) == -1)
    {
      endwin();
      return (NULL);
    }
  if (init_sequences(config, env) == -1)
    return (NULL);
  if (get_highscore(config) == -1)
    return (NULL);
  debug_part(config, &tetri);
  prep_screen();
  clean_list(&tetri);
  config->form = choose_tetrimino(tetri);
  config->next = choose_tetrimino(tetri);
  config->pos[0] = (config->width / 2) - (config->form->width / 2);
  display_game(config, 1);
  return (tetri);
}

int			main(int ac, char **av, char **env)
{
  t_config		config;
  t_tetrimino		*tetri;
  char			key[10];
  int			c;
  struct winsize	win;

  if ((tetri = init_main(av, env, &config, tetri)) == NULL)
    return (-1);
  c = 0;
  key[0] = 0;
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
      usleep(get_speed(config.speed, config.level));
    }
  endwin();
}
