/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:12:12 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/17 17:52:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	lx_free_cmd(t_cmd *line)
{
	t_more	*tmp;
	t_more	*todel;

	tmp = line->more;
	while (tmp != NULL)
	{
		todel = tmp;
		tmp = tmp->next;
		if (todel != NULL && todel->str != NULL)
			ft_memdel((void **)&todel->str);
		if (todel)
			ft_memdel((void **)&todel);
	}
}

void		lx_full_free(t_data *d)
{
	t_cmd	*tmp;
	t_cmd	*todel;

	tmp = d->lst_line;
	while (tmp != NULL)
	{
		todel = tmp;
		tmp = tmp->next;
		lx_free_cmd(todel);
		if (todel && todel->cmd)
			ft_memdel((void **)&todel->cmd);
		if (todel)
			ft_memdel((void **)&todel);
	}
	if (d->line)
		ft_memdel((void **)d->lst_line);
	d->lst_line = NULL;
}
