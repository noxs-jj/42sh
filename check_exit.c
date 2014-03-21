/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:04:57 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/21 12:09:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** check comman is "exit" is present, call free and exit
** TEST OK jmoiroux
*/

void	check_exit(t_data *d)
{
	if (d->line != NULL && d->line != '\0')
	{
		if ((ft_strequ("exit", d->line) == 1)
			&& (d->line[4] == '\0' || d->line[4] == ' '))
		{
			d->toexec = ft_strtrim(d->line);
			build_exit(d);
		}
	}
}
