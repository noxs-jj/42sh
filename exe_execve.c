/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:15:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 17:14:12 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/* split = ft_getexe(d->tree->command, d->env); */

int			exe_execve(t_data *d)
{
	char		**split;

	split = ft_getexe(d->line, d->env);
	if (split != NULL)
		execve(split[0], split, d->env);
	return (-1);
}
