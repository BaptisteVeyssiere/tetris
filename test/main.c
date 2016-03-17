#include <ncurses.h>

int	main()
{
  char	buf[2];

  write(1, "k", 1);
  read(0, buf, 1);
  return (0);
}
