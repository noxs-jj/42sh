/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_putenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:28:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/24 15:35:04 by vjacquie         ###   ########.fr       */
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

static char		**realloc_2d(char ***old_ptr, size_t new_size)
{
	char		**new_ptr;
	size_t		i;

	i = 0;
	if ((new_ptr = (char **)malloc(new_size * sizeof(char *))) == NULL)
	{
		return (NULL);
	}
	ft_bzero(new_ptr, new_size);
	while ((*old_ptr)[i] != NULL)
	{
		new_ptr[i] = (*old_ptr)[i];
		i++;
	}
	new_ptr[i] = NULL;
	free(*old_ptr);
	*old_ptr = NULL;
	return (new_ptr);
}

void			ft_putenv(t_data *d)
{
	char	*new_var;
	char	**old_ptr;
	size_t	i;

	if ((new_var = ft_memalloc(ft_strlen(d->varenv)
		+ ft_strlen(d->valenv) + 1)) != NULL)
	{
		new_var = ft_strcpy(new_var, d->varenv);
		new_var = ft_strcat(new_var, "=");
		new_var = ft_strcat(new_var, d->valenv);
	}
	else
	{
		WR(2, "Malloc error: could not allocate new variable\n");
		d->current->exedone = 1;
		return ;
	}
	old_ptr = d->env;
	d->env = realloc_2d(&old_ptr, arraylen(old_ptr) + 4);
	i = 0;
	while (d->env[i] != NULL)
		++i;
	d->env[i] = new_var;
	d->env[i + 1] = NULL;
}
