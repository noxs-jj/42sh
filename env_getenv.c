/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:26:46 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/03 12:01:10 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Return values:
** NULL if *str is not found in **env
** Otherwise, returns an allocated COPY of the string found in **env
** TEST maybe OK need explain to confirm test, jmoiroux
*/

char		*ft_getenv(char *str, char **env)
{
	size_t	i;
	char	*tmp;

	if ((tmp = ft_memalloc(ft_strlen(str) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, str);
		tmp = ft_strcat(tmp, "=");
	}
	else
	{
		ft_putendl("Malloc error: could not allocate tmp");
		return (NULL);
	}
	i = 0;
	while (env[i] && *env[i] != '\0'
			&& ft_strncmp(env[i], tmp, ft_strlen(tmp)) != 0)
		++i;
	free(tmp);
	if (env[i] == NULL || env[i][0] == '\0')
	{
		return (NULL);
	}
	return (ft_strdup(ft_strchr(env[i], '=')) + 1);
}

char		*env_getenv(t_data *d)
{
	return (ft_getenv(d->varenv, d->env));
}