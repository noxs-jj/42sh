/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_putenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:28:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 16:56:35 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Takes the ADDRESS of a string of strings
** Frees each strings one by one
** Frees main string of strings
** Set value of the main pointer to NULL
*/

void		ft_putenv(char ***env, char *var, char *val)
{
	char	*tmp;

	if ((tmp = ft_memalloc(ft_strlen(var) + ft_strlen(val) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, var);
		tmp = ft_strcat(tmp, "=");
		tmp = ft_strcat(tmp, val);
	}
	else
	{
		ft_putendl("Malloc error: could not allocate new variable");
		return ;
	}
	*env = ft_realloc(*env, sizeof(char *) * (arraylen(*env) + 3));
	(*env)[arraylen(*env)] = tmp;
	(*env)[arraylen(*env) + 1] = NULL;
}

void		env_putenv(t_data *d)
{
	ft_putenv(&d->env, d->varenv, d->valenv);
}
