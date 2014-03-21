/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:02 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/21 14:50:45 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	freeall(t_data *d);

/*
** Exit on command
** TEST OK jmoiroux
*/

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

static void	freeall(t_data *d)
{
	if (d->line != NULL)
		ft_memdel((void **)&d->line);
	if (d->toexec != NULL)
		ft_memdel((void **)&d->toexec);
	if (d->argv != NULL)
		ft_memdel((void **)&d->argv);
	if (d->env != NULL)
		free_tabtab(d->env);
	if (d->varenv != NULL)
		ft_memdel((void **)&d->varenv);
	if (d->valenv != NULL)
		ft_memdel((void **)&d->valenv);
	if (d->lst_line != NULL)
		lx_full_free(d);
	if (d != NULL)
		ft_memdel((void **)&d);
}
