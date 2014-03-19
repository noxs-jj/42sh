/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:02 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/19 16:20:18 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Exit on command
** TEST OK
*/

void	build_exit(t_data *d)
{
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
	_exit(1);
}
