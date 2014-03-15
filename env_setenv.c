/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:39:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/15 12:08:50 by jmoiroux         ###   ########.fr       */
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
	d->varenv = var;
	d->valenv = val;
	env_setenv(d);
}

static void	env_setenv2(t_data *d)
{
	char	*tmp;

	d->env = ft_realloc(d->env, sizeof(char *) * (arraylen(d->env) + 3));
	if (d->env == NULL)
	{
		WR(2, "Malloc error on (ft_realloc env_setenv)");
		return ;
	}
	if ((tmp = ft_memalloc(ft_strlen(d->varenv)
			+ ft_strlen(d->valenv) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, d->varenv);
		tmp = ft_strcat(tmp, "=");
		tmp = ft_strcat(tmp, d->valenv);
	}
	else
	{
		WR(2, "Malloc error: could not allocate variable (env_setenv)");
		return ;
	}
	d->env[ft_get_var_index(d->env, d->varenv)] = tmp;
}

void		env_setenv(t_data *d)
{
	if (d->varenv != NULL && d->valenv != NULL)
	{
		if (ft_getenv(d->varenv, d->env) == NULL)
			ft_putenv(d);
		else
			env_setenv2(d);
	}
	else
		ft_putstr("setenv usage: 'setenv variable value'\n");
}
