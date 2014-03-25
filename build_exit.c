/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:02 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/25 23:22:16 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Exit on command
** TEST OK jmoiroux
*/

static void	freeall(t_data *d)
{
	if (d != NULL)
	{
		if (d->line != NULL)
			ft_memdel((void **)&d->line);
		if (ft_strlen(d->toexec) > 0)
		{
			if (d->toexec[0] != 4)
				free(d->toexec);
			d->toexec = NULL;
		}
		if (d->argv != NULL)
			ft_memdel((void **)&d->argv);
		if (d->cenv != NULL)
			free_tabtab(d->cenv);
		if (d->varenv != NULL)
			ft_memdel((void **)&d->varenv);
		if (d->valenv != NULL)
			ft_memdel((void **)&d->valenv);
		if (d->lst_line != NULL)
			lx_full_free(d);
		if (d != NULL)
			ft_memdel((void **)&d);
	}
}

void		build_exit(t_data *d)
{
	int	i;

	i = 0;
	if (ft_strlen(d->toexec) >= 5)
	{
		i = ft_atoi(&d->toexec[4]);
		i = i % 256;
	}
	freeall(d);
	_exit(i);
}
