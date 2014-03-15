/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:55:55 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/15 16:00:44 by jmoiroux         ###   ########.fr       */
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
	d->env = NULL;
	d->line = NULL;
	d->varenv = NULL;
	d->valenv = NULL;
	d->lst_line = NULL;
	d->statprev = 0;
	signal(SIGINT, ft_ctrl_c);
//	signal(SIGPIPE, SIG_IGN);
	env_copy(d);
}
