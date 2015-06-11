/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 17:56:00 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 17:49:46 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, t_env *e)
{
  ft_putstr("keycode : ");
  ft_putnbr(keycode);
  ft_putchar('\n');
  if (keycode == 53)
    exit(0);
  else if (keycode == 24)
  {
    (e->taille) += 2;
    (e->y) -= (e->y);
    (e->x) -= (e->x);
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  else if (keycode == 27)
  {
    (e->taille) -= 1;
    (e->y) += (e->y);
    (e->x) += (e->x);
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  else if (keycode == 125)
  {
    (e->y) += 10;
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  else if (keycode == 126)
  {
    (e->y) -= 10;
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  else if (keycode == 124)
  {
    (e->x) += 10;
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  else if (keycode == 123)
  {
    (e->x) -= 10;
    ft_bzero((e->addr), ((e->sizeline) * ((e->res)[1])));
    expose_hook(e);
  }
  return (0);
}
