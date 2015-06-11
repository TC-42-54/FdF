/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_linenb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 10:03:48 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/07 10:09:26 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int read_linenb(char *file)
{
	int fd;
	int linenb;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("open() error...");
		return(-1);
	}
	linenb = getlinenb(fd);
	close(fd);
	return (linenb);
}
