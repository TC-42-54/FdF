/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 17:56:00 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 15:51:54 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, t_env *e)
{
	ft_putstr("keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	e->mlx = e->mlx;
	if (keycode == 53)
		exit(0);
	/*if (keycode == 24)
	{
		(e->taille) += 10;
		e->img = mlx_new_image(e->mlx, (e->res)[0], (e->res)[1]);
		e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
		expose_hook(e);
		}*/
	return (0);
}
