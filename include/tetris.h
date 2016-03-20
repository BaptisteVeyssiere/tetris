/*
** tetris.h for tetris in /home/scutar_n/rendu/PSU/PSU_2015_tetris
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Mar  2 14:16:12 2016 nathan scutari
** Last update Sun Mar 20 21:42:29 2016 nathan scutari
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define _DEFAULT_SOURCE
# define UNUSED __attribute__((unused))

# include <stdlib.h>
# include <ncurses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <time.h>
# include <termios.h>
# include <ncurses/curses.h>
# include <term.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>

# undef lines
# undef tab

typedef struct		s_tetrimino
{
  int			width;
  int			height;
  int			color;
  char			error;
  char			*name;
  char			**form;
  struct s_tetrimino	*next;
}			t_tetrimino;

typedef struct
{
  char			turn;
  char			drop;
  char			left;
  char			right;
  char			quit;
  char			pause;
  char			hide;
  char			debug;
  char			help;
}			t_doublon;

typedef struct
{
  char                  *right;
  char                  *left;
  int                   level;
  int                   played;
  char                  lines;
  int                   speed;
  int                   score;
  int                   highscore;
  char                  combo;
  char                  debug;
  char                  *turn;
  char                  *drop;
  char			error;
  char                  *pause;
  char                  brek;
  char                  *quit;
  char                  hide;
  int                   time;
  int                   width;
  int                   height;
  int                   pos[2];
  char                  **map;
  t_tetrimino           *form;
  t_tetrimino           *next;
  t_doublon		doublon;
}                       t_config;

/*
**debug.c
*/
void	my_debugstr(char*);
void	print_keys(t_config*);
void	debug_part(t_config*, t_tetrimino**);
void    clean_list(t_tetrimino**);
void    print_form(t_tetrimino*);

/*
**display_dec.c
*/
void	display_next(t_config*);
void	bottom_and_stats(t_config*);

/*
**drop_bomb.c
*/
void	drop_tetri(t_config*, int, t_tetrimino*);

/*
**end_game.c
*/
int	save_scores(t_config*);
int	end_game(t_config*, char*);
int	get_highscore(t_config*);

/*
**fill_key.c
*/
void	fill_key(char**, char*);
void	get_entry(char*);
int	compare_key(char*, char*);

/*
**form_wordtab.c
*/
char	**get_form_wordtab(int, int);
int	tetri_in_list(t_tetrimino**);
void	my_fillstr(char*, char*);
int	is_tetrimino(char*);
char	*get_fullname(char*);

/*
**game_physic.c
*/
int	gravity_ok(t_config*);
void	moving_in_non_movings(t_config*);
int	new_form(t_config*, t_tetrimino*);
int	game_physics(t_config*, t_tetrimino*);

/*
**game_success.c
*/
void	line_complete(t_config*, int);
int	game_finished(t_config*);
void	is_line_complete(t_config*);

/*
**get_long_args_bis.c
*/
char	**get_long_compare_table();
int	config_print(int, t_config*, char*);

/*
**get_long_args.c
*/
int	config_nbrs(int, t_config*, char*);
int	config_controls(int, t_config*, char*);
int	config_pandq(int, t_config*, char*);
int	compare_largs(char*, char*);
int	get_next_long_config(char**, int, t_config*);

/*
**get_term.c
*/
char	*get_term(char**);
void	init_config_values(t_config*);

/*
**help.c
*/
void	display_help(char*);

/*
**init_config.c
*/
t_tetrimino	*choose_tetrimino(t_tetrimino*);
void		display_non_movings(t_config*);
void		display_moving(t_config*);
void		display_game(t_config*, int);
int		init_config(t_config*);

/*
**key_control.c
*/
void	right_move(t_config*);
void	left_move(t_config*);
void	is_movement_key(char*, t_config*, t_tetrimino*);
void	key_control(char*, t_config*, t_tetrimino*);

/*
**load_tetrimino.c
*/
void	print_info(int, int, int, char*);
int	display_error(char*);
char	*get_name(char*);
int	get_tetrimino_info(int, char*, t_tetrimino**);
int	load_tetriminos(t_tetrimino**);

/*
**main.c
*/
void		init_ioctl();
void		prep_screen();
int		init_sequences(t_config *, char **);
t_tetrimino	*init_main(char**, char**, t_config*, t_tetrimino*);
int		main(int, char**, char**);

/*
**my_getnbr.c
*/
int	is_overflow(char*, int);
int	syntax_check(char*);
int	my_getnbr(char*);

/*
**my_put_nbr.c
*/
int	my_put_nbr(int);

/*
**sort_list.c
*/
void	sort_list(t_tetrimino**);
int	compare_size(t_tetrimino*, t_tetrimino*);
void	swap_list(t_tetrimino*, t_tetrimino*, t_tetrimino*, t_tetrimino**);
void    sort_error_list(t_tetrimino**);

/*
**speed.c
*/
int	get_speed(int, int);

/*
**tetrimino_info.c
*/
int	get_width(int);
int	get_height(int);
int	get_color(int);
int	check_form(int, int, int, char***);

/*
**tetri_rotation.c
*/
void	free_and_replace(t_config*, char**);
void	rotation_tetri(t_config*, char**);
int	turn_tetri(t_config*);

/*
**tools.c
*/
char	*my_realloc(char, char*);
void	my_putchar(char);
void	my_putstr(char*);
int	my_strlen(char*);
int	my_perror(char*);

/*
**user_config_bis.c
*/
void	fill_compare(char**, char*);
char	**get_short_compare_table();
int	comare_args(char*, char*);
int     compare_args(char*, char*);
void    init_doublon(t_doublon*);

/*
**user_config.c
*/
int	get_control_config(char*, t_config*, int);
int	get_other_config(char*, t_config*, int);
int	get_wd(t_config*, int);
int	get_next_config(char**, int, t_config*);
int	user_config(char**, t_config*);

/*
**check_tetriminos.c
*/
int	verify_lines(char **, int, int);
int	verify_columns(char **, int, int);

/*
**get_next_line.c
*/
char	*get_next_line(int);

#endif /* !TETRIS_H_ */
