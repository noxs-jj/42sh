/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 11:23:28 by scohen            #+#    #+#             */
/*   Updated: 2014/02/28 16:51:11 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_envcpy(t_data *d)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = arraylen(environ);
	d->env = (char **)ft_memalloc(len * (sizeof(char *) + 2));
	if (d->env == NULL)
	{
		ft_putendl("Malloc error: could not copy environement");
		return (NULL);
	}
	while (i < len)
	{
		d->env[i] = ft_strdup(environ[i]);
		++i;
	}
	d->env[i] = ft_strdup("\0");
	d->env[i + 1] = NULL;
}
