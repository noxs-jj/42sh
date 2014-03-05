/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_detail_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:51:20 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/05 15:04:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** create a new detail link with the cmd line
** TEST OK vjacquie
*/

t_more	*lx_new_more(char *str, int n)
{
	t_more	*new;

	new = (t_more *)malloc(sizeof(t_more));
	new->str = str;
	new->end = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*
** add a new detail link
** TEST OK vjacquie
*/

void	lx_add_more(t_cmd *op, t_more *new)
{
	t_more	*tmp;

	tmp = op->more;
	if (tmp == NULL)
		op->more = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
