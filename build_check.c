/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:53:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/25 23:49:31 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Check what builtin is used et lunch function
** TEST OK jmoiroux
*/

int		build_check(t_data *d)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (d->line != NULL && d->toexec[0] != '\0')
	{
		while (g_tab[i].str != '\0')
		{
			len = ft_strlen(g_tab[i].str);
			if ((ft_strnequ(g_tab[i].str, d->toexec, len) == 1)
				&& (len <= ft_strlen(d->toexec))
				&& (d->toexec[len] == '\0' || d->toexec[len] == ' '
				|| d->toexec[len] == '\t'))
			{
				g_tab[i].fptr(d);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
