/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:23:50 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/27 15:23:09 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** get extern environ and copy it on char **env in struct data
** if no environement soft say to retry with env
*/

void	env_copy(t_data *d)
{
	size_t	len;
	size_t	i;

	if (d->envmain == NULL)
		ft_exit(d, "Cannot run without an environement.");
	i = 0;
	len = arraylen(d->envmain);
	d->cenv = (char **)malloc(sizeof(char *) * (1 + len));
	while (i < len)
	{
		d->cenv[i] = ft_strdup(d->envmain[i]);
		++i;
	}
	d->cenv[i] = NULL;
}
