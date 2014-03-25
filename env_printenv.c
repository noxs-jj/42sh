/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_printenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/24 16:32:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** print envcopy
** TEST OK jmoiroux
*/

void	env_printenv(t_data *d)
{
	int		i;

	i = 0;
	while (d->cenv[i] != NULL && d->cenv[i][0] != '\0')
	{
		ft_putendl(d->cenv[i]);
		++i;
	}
}
