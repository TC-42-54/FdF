/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 10:11:26 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/07 10:37:33 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **read_table(char *file, int **zval, int **nbcases)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("open() error...");
		return (NULL);
	}
	zval = gettable(fd, zval, nbcases);
	close(fd);
	return (zval);
}
