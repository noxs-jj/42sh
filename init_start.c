/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:55:55 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/03 13:02:29 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** init all vars on struct data
** TEST OK jmoiroux
*/

void	init_start(t_data *d)
{
	d->env = NULL;
	d->buff = NULL;
	d->line = NULL;
	d->tree = NULL;
	d->varenv = NULL;
	d->valenv = NULL;
}
