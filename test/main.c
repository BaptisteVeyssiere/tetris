#include <sys/ioctl.h>
#include <termios.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

struct termios		init_ioctl()
{
  struct termios	term;
  struct termios	copy;

  if (ioctl(0, TCGETS, &term) != 0)
    printf("ioctl G prob\n");
  copy = term;
  term.c_lflag &= ~(ECHO | ICANON);
  term.c_cc[VMIN] = 0;
  term.c_cc[VTIME] = 0;

  if (ioctl(0, TCSETS, &term) != 0)
    printf("ioctl S prob\n");
  return (copy);
}

int	main()
{
  char	buf[4];
  struct termios	term;
  char	*s;
  int	i;

  /* initscr(); */
  /* if (ioctl(0, TCGETS, &term) != 0) */
  /*   printf("ioctl G prob\n"); */
  /* term.c_cc[VMIN] = 0; */
  /* ioctl(0, TCSETS, &term); */
  /* buf[0] = 0; */
  /* buf[1] = 0; */
  /*tputs(tigetstr("kcud1"), 1, putchar);*/
  if ((s = tigetstr("kcud1")) == NULL)
    return (-1);
  i = -1;
  while (s[++i] != 0)
    write(1, &(s[i]), 1);
  /*while (buf[0] != 27 || buf[1] != 0)
    {
      buf[0] = 0;
      buf[1] = 0;
      buf[2] = 0;
      buf[3] = 0;
      read(0, buf, 3);
      if (buf[0] != 0)
	printw("'%s' -> '%d'\n", buf, buf[0]);
      refresh();
    }*/
  /* endwin(); */
      return (0);
}

/* int			main(int ac, char **av) */
/* { */
/*   char			c; */
/*   int			i; */
/*   struct termios	copy; */
/*   char	*s; */
/*   int	d; */

/*   /\*copy = init_ioctl();*\/ */
/*   initscr(); */
/*   raw(); */
/*   /\*setupterm("xterm", 1, &i);*\/ */
/*   /\* s  = tigetstr("kcud1"); *\/ */
/*   /\* s++; *\/ */
/*   /\* d = -1; *\/ */
/*   /\* while (s[++d] != 0) *\/ */
/*   /\*   write(1, &s[d], 1); *\/ */
/*   c = 0; */
/*   while (c != 27) */
/*     { */
/*       c = 0; */
/*       read(0, &c, 1); */
/*       if (c != 0) */
/* 	printf("'%c' -> '%d'\n", c, c); */
/*       if (c == 10) */
/* 	{ */
/* 	  endwin(); */
/* 	  return (-1); */
/* 	} */
/*     } */
/*   /\*if (ioctl(0, TCSETS, &copy) != 0) */
/*     printf("ioctl S prob\n");*\/ */
/*   endwin(); */
/*   return (0); */
/* } */
