/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_envdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:31 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/27 15:23:13 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		env_envdel(t_data *d)
{
	int		i;

	i = 0;
	while (d && d->cenv && d->cenv[i])
	{
		if (d && d->cenv && d->cenv[i])
			ft_memdel((void **)&d->cenv[i]);
		i++;
	}
	if (d && d->cenv)
		ft_memdel((void **)&d->cenv);
}
