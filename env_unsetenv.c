/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:08:01 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:49:23 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_unsetenv(char *str, char **env)
{
	size_t	len;
	char	**ptr;

	if (str == NULL || *str == '\0' || ft_strchr (str, '=') != NULL)
		return ;
	len = ft_strlen(str);
	while (*env != NULL)
	{
		if (ft_strncmp(*env, str, len) == 0 && (*env)[len] == '=')
		{
			ptr = env;
			while (*ptr)
			{
				ptr[0] = ptr[1];
				++ptr;
			}
		}
		else
			++env;
	}
}

void		env_unsetenv(t_data *d)
{
	ft_unsetenv(d->varenv, d->env);
}
