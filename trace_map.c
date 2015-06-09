
#include "fdf.h"

void trace_map(t_env *e, int x, int y)
{
    int *var;

    var = (int *)malloc(sizeof(int) * 4);
    ft_putendl("trace map");
    var[0] = 0;
    var[1] = 0;
    var[2] = 0;
    var[3] = 0;

    while ((e->zval)[(var)[0]] != NULL)
      sub_trace_map(e, &(var), x, y);
}

void sub_trace_map(t_env *e, int **var, int x, int y)
{
  (*var)[3] = (y + ((e->taille) * (*var)[0])) - ((e->res)[1] * 0.25);
  while (((*var)[1] + 1) <= ((e->nbcases)[(*var)[0]]))
  {
    (*var)[2] = (x + ((e->taille) * (*var)[1]) + ((e->res)[0] * 0.25));
    if (((*var)[1] + 1) < ((e->nbcases)[(*var)[0]]))
    {
      if ((((e->zval)[(*var)[0]][(*var)[1]] != 0) ||
	   ((e->zval)[(*var)[0]][(*var)[1] + 1] != 0)))
	h_red_line(e, (*var)[2], (*var)[3], var);
      else if ((e->zval)[(*var)[0]][(*var)[1]] == 0)
	h_blue_line(e, (*var)[2], (*var)[3], var);
    }
    if ((e->zval)[(*var)[0] + 1] != NULL)
    {
      if ((((e->zval)[(*var)[0]][(*var)[1]] != 0) ||
	   ((e->zval)[(*var)[0] + 1][(*var)[1]] != 0)))
	v_red_line(e, (*var)[2], (*var)[3], var);
      else
	v_blue_line(e, (*var)[2], (*var)[3], var);
    }
    (*var)[1]++;
  }
  (*var)[1] = 0;
  (*var)[0]++;
}
