/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 20:05:00 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/06 20:09:55 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int blue_line(t_env *e, int x1, int y1)
{
    double coordy;
    double coordx;
    int x;
    int y;
    int size;

    coordy = 0.0;
    coordx = 0.0;
    if ((x1 <= (x1 + (e->taille))) &&
	(((x1 + (e->taille)) - x1) >= abs((y1 + (e->taille)) - y1)))
      {
	x = x1;
	while (x <= (x1 + (e->taille)) && x <= (int)(e->res[0]))
	  {
	    coordy = y1 + ((((y1 + (e->taille)) - y1) *
			    (x - x1)) / ((x1 + (e->taille)) - x1));
	    size = (x * 4) + (coordy * (e->sizeline));
	    (e->addr)[size] = 255;
	    // mlx_pixel_put(e->mlx, e->win, x, coordy, color);
	    x++;
	  }
      }
    else
      {
	y = y1;
	while (y <= (y1 + (e->taille)) && y <= (int)(e->res[1]))
	  {
	    coordx = x1 + ((((x1 + (e->taille)) - x1) *
			    (y - y1) / ((y1 + (e->taille)) - y1)));
	    size = (coordx * 4) + (y * (e->sizeline));
	    (e->addr)[size] = 255;
	    //mlx_pixel_put(e->mlx, e->win, coordx, y, color);
	    y++;
	  }
      }
    return (0);
}
