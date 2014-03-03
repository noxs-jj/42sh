/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:08:01 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/03 11:49:51 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** remove entry called fron build_unsetenv or cd
** TEST OK jmoiroux
*/

void	env_unsetenv(t_data *d)
{
	size_t	len;
	char	**ptr;
	int		i;

	if (d->varenv == NULL || d->varenv == '\0'
		|| ft_strchr (d->varenv, '=') != NULL)
		return ;
	len = ft_strlen(d->varenv);
	i = 0;
	while (d->env[i] != NULL)
	{
		if (ft_strncmp(d->env[i], d->varenv, len) == 0 && d->env[i][len] == '=')
		{
			ptr = &(d->env[i]);
			while (*ptr)
			{
				ptr[0] = ptr[1];
				++ptr;
			}
		}
		else
			i++;
	}
}
