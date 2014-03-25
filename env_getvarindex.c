/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getvarindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:30:51 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/24 15:34:59 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	ft_get_var_index(char **env, char *str)
{
	size_t	i;
	char	*tmp;
	t_data	*d;

	d = dataptr(NULL);
	if ((tmp = ft_memalloc(ft_strlen(str) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, str);
		tmp = ft_strcat(tmp, "=");
	}
	else
	{
		WR(2, "Malloc error: could not allocate tmp\n");
		d->current->exedone = 1;
		return (-1);
	}
	i = 0;
	while (*env[i] != '\0' && ft_strncmp(env[i], tmp, ft_strlen(tmp)) != 0)
		++i;
	ft_memdel((void **)&tmp);
	if (env[i][0] == '\0')
		return (-1);
	return (i);
}

int	env_getvarindex(t_data *d)
{
	return (ft_get_var_index(d->cenv, d->varenv));
}
