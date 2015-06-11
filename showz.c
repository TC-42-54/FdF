#include "fdf.h"

int showz4x(int x, int y, int z)
{
  double coordx;
  double roty;
  double rotz;

  //if (z > 0)
  //z = z + 10;
  //else
  //  z = z - 10;
  roty = ((2 * M_PI) / 60);
  rotz = ((2 * M_PI) / 15.65);
  coordx = ((x * cos(rotz)) - (y * sin(rotz)));
  coordx = ((coordx * cos(roty)) + ((z) * sin(roty)));
  /*ft_putendl("//////////////");
  ft_putstr("x : ");
  ft_putnbr((int)coordx);
  ft_putchar('\n');
  ft_putendl("//////////////");*/
  return ((int)coordx);
}

int showz4y(int x, int y, int z)
{
  double coordy;
  double rotx;
  double rotz;

  //if (z > 0)
  //  z = z + 10;
  //else
  //  z = z - 10;
  rotx = ((2 * M_PI) / 10.65);
  rotz = ((2 * M_PI) / 13.65);
  coordy = ((x * sin(rotz)) + (y * cos(rotz)));
  coordy = ((coordy * cos(rotx)) - ((z) * sin(rotx)));
  /*ft_putendl("//////////////");
  ft_putstr("y : ");
  ft_putnbr((int)coordy);
  ft_putchar('\n');
  ft_putendl("//////////////");*/
  return ((int)coordy);
}
