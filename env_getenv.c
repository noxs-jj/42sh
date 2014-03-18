/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:26:46 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/17 12:35:41 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Return values:
** NULL if *str is not found in **env
** Otherwise, returns an allocated COPY of the string found in **env
** TEST maybe OK need explain to confirm test, jmoiroux
*/

char		*ft_getenv(char *var, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL && (!ft_strnequ(env[i], var, ft_strlen(var))
		|| (size_t)(ft_strchr(env[i], '=') - env[i]) != ft_strlen(var)))
		++i;
	if (env != NULL && env[i] != NULL)
	{
		return (ft_strdup(ft_strchr(env[i], '=') + 1));
	}
	return (NULL);
}

char		*env_getenv(t_data *d)
{
	return (ft_getenv(d->varenv, d->env));
}
