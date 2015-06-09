/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 17:56:00 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/06 18:01:04 by tchezier         ###   ########.fr       */
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
	return (0);
}
