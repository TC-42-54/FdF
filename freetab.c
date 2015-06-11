/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 16:02:21 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 18:06:44 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void freetab(char ***table, int cases)
{
	int i;

	i = 0;
	//ft_putendl("we're going to free the table.");
	while (((*table)[i] != NULL) && (i < cases))
	{
		free((*table)[i]);
		i++;
	}
	free(*table);
	//ft_putendl("the table is now empty.");
}
