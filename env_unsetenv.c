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
	char	*tofree;
	int	i;

	i = 0;
	tofree = NULL;
	while (d->env[i] != NULL && (!ft_strnequ(d->env[i], d->varenv, ft_strlen(d->varenv))
		|| (size_t)(ft_strchr(d->env[i], '=') - d->env[i]) != ft_strlen(d->varenv)))
		++i;
	if (d->env[i] != NULL)
	{
		tofree = d->env[i];
		while (d->env[i] != NULL)
		{
			d->env[i] = d->env[i + 1];
			++i;
		}
	}
	ft_strdel(&tofree);
}
