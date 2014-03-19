/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:12:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/19 18:09:41 by nmohamed         ###   ########.fr       */
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
		return ;
	}
	if (tmp[1] == NULL)
	{
		ft_putstr("unsetenv usage: 'unsetenv variable'\n");
		return ;
	}
	d->varenv = tmp[1];
	env_unsetenv(d);
	if (tmp[0] != NULL)
		ft_memdel((void **)&tmp[0]);
	free(tmp);
}
