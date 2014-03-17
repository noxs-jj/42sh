/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:29:45 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/17 17:50:31 by jmoiroux         ###   ########.fr       */
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

	tmp = ft_strsplit(d->line, ' ');
	if (tmp == NULL)
	{
		WR(2, "Split error (build_env)\n");
		return ;
	}
	if (tmp[1] != NULL)
		d->varenv = tmp[1];
	if (tmp[2] != NULL)
		d->valenv = tmp[2];
	env_setenv(d);
	if (d->varenv != NULL)
		ft_memdel((void **)&(d->varenv));
	d->valenv = NULL;
	if (tmp != NULL && tmp[0] != NULL)
		ft_memdel((void **)&tmp[0]);
	if (tmp != NULL)
	ft_memdel((void **)&tmp);
}
