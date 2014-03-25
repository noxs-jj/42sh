/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:55:55 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/24 17:38:38 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** init all vars on struct data
** Load signals
** do env copy
** TEST OK jmoiroux
*/

void	init_start(t_data *d)
{
	d->cmdrun = 0;
	d->cenv = NULL;
	d->line = NULL;
	d->varenv = NULL;
	d->valenv = NULL;
	d->lst_line = NULL;
	d->statprev = 0;
	d->current = NULL;
	signal(SIGINT, ft_ctrl_c);
	dataptr(d);
	env_copy(d);
}
