/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 16:10:57 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/06 17:53:12 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
 
int ft_win(size_t x, size_t y, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, x, y, "My Fuckin' FdF");
	e->img = mlx_new_image(e->mlx, x, y);
	e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
