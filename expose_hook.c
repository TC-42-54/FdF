/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 17:54:48 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 17:06:05 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int expose_hook(t_env *e)
{
  int status;

  ft_putendl("we are in expose hook");
  status = 0;
  trace_map(e, (e->x), (e->y));
  status = mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  //e->mlx = e->mlx;
  return (0);
}
