/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:12:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/25 16:51:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** remove line on env called from command
** TEST OK jmoiroux
*/

void	build_unsetenv(t_data *d)
{
	char	**tmp;

	ft_replace('\t', ' ', d->line);
	tmp = ft_strsplit(d->line, ' ');
	if (tmp == NULL)
	{
		WR(2, "Split error (build_unsetenv)\n");
		d->current->exedone = 1;
		return ;
	}
	if (tmp[1] == NULL || tmp[2] != NULL)
	{
		ft_putstr("Unsetenv usage: 'unsetenv variable' only\n");
		d->current->exedone = 1;
		return ;
	}
	d->varenv = tmp[1];
	env_unsetenv(d);
	if (tmp[0] != NULL)
		ft_memdel((void **)&tmp[0]);
	free(tmp);
}
