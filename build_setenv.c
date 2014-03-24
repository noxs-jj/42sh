/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:29:45 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/24 15:11:49 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Add entry from command, call env_setenv()
** TEST OK jmoiroux check free valenv line 37
*/

void	build_setenv(t_data *d)
{
	char	**tmp;

	ft_replace('\t', ' ', d->line);
	tmp = ft_strsplit(d->line, ' ');
	if (tmp == NULL)
	{
		WR(2, "Split error (build_env)\n");
		d->current->exedone = 1;
		return ;
	}
	if (tmp[1] != NULL && tmp[2] != NULL)
	{
		d->varenv = tmp[1];
		d->valenv = tmp[2];
	}
	env_setenv(d);
	if (d->varenv != NULL)
		ft_memdel((void **)&(d->varenv));
	if (d->valenv != NULL)
		ft_memdel((void **)&d->valenv);
	ft_memdel((void **)&tmp[0]);
	free(tmp);
}
