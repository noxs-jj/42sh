/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:23:50 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 14:25:18 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// static char	**ft_envcpy(char **env)
// {
// 	char	**new;
// 	size_t	len;
// 	size_t	i;

// 	i = 0;
// 	len = arraylen(environ);
// 	new = (char **)ft_memalloc(len * (sizeof(char *) + 2));
// 	if (new == NULL)
// 	{
// 		ft_putendl("Malloc error: could not copy environement");
// 		return (NULL);
// 	}
// 	while (i < len)
// 	{
// 		new[i] = ft_strdup(env[i]);
// 		++i;
// 	}
// 	new[i] = ft_strdup("\0");
// 	new[i + 1] = NULL;
// 	return (new);
// }

void	env_copy(t_data *d)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = arraylen(environ);
	d->env = (char **)ft_memalloc(len * (sizeof(char *) + 2));
	if (d->env == NULL)
	{
		ft_putendl("Malloc error: could not copy environement");
		return ;
	}
	while (i < len)
	{
		d->env[i] = ft_strdup(environ[i]);
		++i;
	}
	d->env[i] = ft_strdup("\0");
	d->env[i + 1] = NULL;
}
