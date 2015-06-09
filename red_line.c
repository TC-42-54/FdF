/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 19:50:48 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/08 20:29:57 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void final_h_red_line(t_env *e, int *coords)
{
  int start;
  int snd;
  int size;
  
  start = coords[0];
  while (start <= (coords[2]))
  {
    if ((start < (int)(e->res[0])) && (start >= 0))
    {
      snd = coords[1] + (((coords[3] - coords[1]) *
			  (start - coords[0])) / (coords[2] - coords[0]));
      if ((snd < (int)(e->res[1])) && (snd >= 0))
	{
	  size = (start * 4) + (snd * (e->sizeline));
	  (e->addr)[size + 2] = 255;
	}
    }
    start++;
  }
}

void final_v_red_line(t_env *e, int *coords)
{
  int start;
  int snd;
  int size;
  
  start = coords[1];
  while (start <= coords[3])
  {
    snd = coords[0] + ((((coords[2] - coords[0]) *
			 (start - coords[1])) / (coords[3] - coords[1])));
    if ((snd < (int)(e->res[0])) && (snd >= 0))
    {
      size = (snd * 4) + (start * e->sizeline);
      (e->addr)[size + 2] = 255;
    }
    start++;
  }
}

int v_red_line(t_env *e, int x1, int y1, int **var)
{
  int		*coords;
  int		y2;

  y2 = y1 + (e->taille);
  coords = (int *)malloc(sizeof(int) * 4);
  coords[0] = showz4x(x1, y1, (e->zval)[(*var)[0]][(*var)[1]]); //x1
  coords[1] = showz4y(x1, y1, (e->zval)[(*var)[0]][(*var)[1]]); //y1
  coords[2] = showz4x(x1, y2, (e->zval)[(*var)[0] + 1][(*var)[1]]); //x2
  coords[3] = showz4y(x1, y2, (e->zval)[(*var)[0] + 1][(*var)[1]]); //y2
  sub_red_line(e, coords);
  return (0);
}

int h_red_line(t_env *e, int x1, int y1, int **var)
{
  int           *coords;
  int           x2;

  x2 = x1 + (e->taille);
  coords = (int *)malloc(sizeof(int) * 4);
  coords[0] = showz4x(x1, y1, (e->zval)[(*var)[0]][(*var)[1]]); //x1
  coords[1] = showz4y(x1, y1, (e->zval)[(*var)[0]][(*var)[1]]);//y1
  coords[2] = showz4x(x2, y1, (e->zval)[(*var)[0]][(*var)[1] + 1]); //x2
  coords[3] = showz4y(x2, y1, (e->zval)[(*var)[0]][(*var)[1] + 1]); //y2
  sub_red_line(e, coords);
  return (0);
}
