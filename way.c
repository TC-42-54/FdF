#include "fdf.h"

void sub_red_line(t_env *e, int *coords)
{
  if ((coords[0] <= coords[2]) &&
      ((coords[2] - coords[0]) >= abs(coords[3] - coords[1])))
    final_h_red_line(e, coords);
  else if ((coords[0] >= coords[2]) && 
	   ((coords[0] - coords[2]) >= abs(coords[3] - coords[1])))
  {
    ft_putendl("................on swappe ici ! ");
    swap_try(&coords[0], &coords[2], &coords[1], &coords[3]);
    final_h_red_line(e, coords);
  }
  else
    final_v_red_line(e, coords);
}

void sub_blue_line(t_env *e, int *coords)
{
  if ((coords[0] <= coords[2]) &&
      ((coords[2] - coords[0]) >= abs(coords[3] - coords[1])))
    final_h_blue_line(e, coords);
  else if ((coords[0] >= coords[2]) &&
           ((coords[0] - coords[2]) >= abs(coords[3] - coords[1])))
    {
      ft_putendl("................on swappe ici ! ");
      swap_try(&coords[0], &coords[2], &coords[1], &coords[3]);
      final_h_blue_line(e, coords);
    }
  else
    final_v_blue_line(e, coords);
}
