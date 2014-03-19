/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_putenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:28:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/19 12:46:32 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Takes the ADDRESS of a string of strings
** Frees each strings one by one
** Frees main string of strings
** Set value of the main pointer to NULL
** TEST OK jmoiroux
*/

void		ft_putenv(t_data *d)
{
	char	*tmp;
	char	**old_ptr;

	if ((tmp = ft_memalloc(ft_strlen(d->varenv)
		+ ft_strlen(d->valenv) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, d->varenv);
		tmp = ft_strcat(tmp, "=");
		tmp = ft_strcat(tmp, d->valenv);
	}
	else
	{
		ft_putendl("Malloc error: could not allocate new variable");
		return ;
	}
	old_ptr = d->env;
	d->env = ft_realloc(d->env, sizeof(char *) * (arraylen(d->env) + 3));
	d->env[arraylen(d->env)] = tmp;
	d->env[arraylen(d->env) + 1] = NULL;
	free(old_ptr);
}
