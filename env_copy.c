/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:23:50 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:23:58 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	**ft_envcpy(char **env)
{
	char	**new;
	size_t	len;
	size_t	i;

	i = 0;
	len = arraylen(env);
	new = (char **)ft_memalloc(len * (sizeof(char *) + 2));
	if (new == NULL)
	{
		ft_putendl("Malloc error: could not copy environement");
		return (NULL);
	}
	while (i < len)
	{
		new[i] = ft_strdup(env[i]);
		++i;
	}
	new[i] = ft_strdup("\0");
	new[i + 1] = NULL;
	return (new);
}

char		**env_copy(t_data *d)
{
	return (ft_envcpy(d->env));
}
