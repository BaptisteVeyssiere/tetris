#include <ncurses.h>
#include <fcntl.h>
#include <sys/stat.h>

int	main(int ac, char **av)
{
  int	he;
  int	fd;

  he = 0;
  fd = open("../stats/score", O_RDWR);
  write(fd, (char *)&he, 4);
}
