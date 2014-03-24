/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cmd_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:51:20 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/24 14:36:33 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** create a new cmd link
** TEST OK vjacquie
*/

t_cmd	*lx_new_cmd(char *str, int n)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->cmd = str;
	new->i = n;
	new->exedone = 0;
	new->next = NULL;
	new->more = NULL;
	return (new);
}

/*
** add a new cmd link
** TEST OK vjacquie
*/

void	lx_add_cmd(t_data *data, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = data->lst_line;
	if (tmp == NULL)
		data->lst_line = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
