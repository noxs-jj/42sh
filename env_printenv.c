/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_printenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/27 15:23:28 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** print envcopy
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
