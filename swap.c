#include "fdf.h"

void swap_try(int *x1, int *x2, int *y1, int *y2)
{
  int tmp;

  tmp = *x1;
  *x1 = *x2;
  *x2 = tmp;
  tmp = *y1;
  *y1 = *y2;
  *y2 = tmp;
}
