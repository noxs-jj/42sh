/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_putenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:28:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/03 12:51:21 by jmoiroux         ###   ########.fr       */
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
		d->env = ft_realloc(d->env, sizeof(char *) * (arraylen(d->env) + 3));
		d->env[arraylen(d->env)] = tmp;
		d->env[arraylen(d->env) + 1] = NULL;
}
