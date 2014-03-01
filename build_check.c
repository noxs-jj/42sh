/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:53:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/01 15:39:51 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Check what builtin is used et lunch function
** TEST
*/

int		build_check(t_data *d)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (d->line != NULL && d->line[0] != '\0')
	{
		while (tab[i].str != '\0')
		{
			len = ft_strlen(tab[i].str);
			if ((ft_strnequ(tab[i].str, d->line, len) == 1)
				&& (len <= ft_strlen(d->line))
				&& (d->line[len] == '\0' || d->line[len] == ' '))
			{
				tab[i].fptr(d);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
