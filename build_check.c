/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:53:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/28 17:22:23 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Check what builtin is used et lunch function
** TEST
*/

int		build_check(t_data *d)
{
	int	i;

	if (d->line != NULL)
	{
		while (t_build[i].str != '\0')
		{
			if (ft_strcmp(t_build[i].str, d->line) == 0)
			{
				t_build[i].fptr(d, str);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
