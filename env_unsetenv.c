/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:08:01 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/19 14:23:21 by nmohamed         ###   ########.fr       */
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
	if (d->env == NULL)
	{
		WR(2, "env is null | ft_getenv\n");
		_exit(1);
	}
	while (d->env[i] != NULL
		&& (ft_strncmp(d->env[i], d->varenv, ft_strlen(d->varenv) != 0)
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
		d->env[i] = NULL;
	}
	if (tofree != NULL)
		ft_strdel(&tofree);
	if (d->varenv != NULL)
		ft_strdel(&d->varenv);
}
