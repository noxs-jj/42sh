/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:39:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/19 14:33:03 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** 2 functions
** env_setenv2()->env_setenv()
*/

/*
** add entry to envtab[] from builtin cd or setenv
** check for FREE
** TEST OK jmoiroux
*/

void		ft_setenv(t_data *d, char *var, char *val)
{
	char		**env;
	char		*tofree;
	char		*toset;

	env = d->env;
	tofree = ft_getenv(var, env);
	if (tofree == NULL)
	{
		d->varenv = var;
		d->valenv = val;
		ft_strdel(&tofree);
		return (ft_putenv(d));
	}
	if ((toset = ft_strnew(ft_strlen(var) + ft_strlen(val))) == NULL)
	{
		ft_strdel(&tofree);
		return ;
	}
	ft_strcpy(toset, var);
	ft_strcat(toset, "=");
	ft_strcat(toset, val);
	env = d->env;
	while (env != NULL && env[0] && (ft_strncmp(*env, var, ft_strlen(var) != 0)
		|| (size_t)(ft_strchr(*env, '=') - *env) != ft_strlen(var)))
		++env;
	if (env == NULL && !env[0])
	{
		ft_strdel(&tofree);
		return ;
	}
	ft_strdel(&tofree);
	tofree = *env;
	*env = toset;
	free(tofree);
}

void		env_setenv(t_data *d)
{
	if (d->varenv != NULL && d->valenv != NULL)
	{
		ft_setenv(d, d->varenv, d->valenv);
	}
	else
		ft_putstr("setenv usage: 'setenv variable value'\n");
}
