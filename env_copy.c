/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:23:50 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/15 10:51:23 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** get extern environ and copy it on char **env in struct data
** if no environement soft say to trtry with env
** TEST OK jmoiroux
*/

void	env_copy(t_data *d)
{
	size_t	len;
	size_t	i;

	if (*environ == NULL)
		ft_exit(d, "Cannot run without an environement.");
	i = 0;
	len = arraylen(environ);
	d->env = (char **)malloc(sizeof(char *) * (1 + len));
	while (i < len)
	{
		d->env[i] = ft_strdup(environ[i]);
		++i;
	}
	d->env[i] = NULL;
}
