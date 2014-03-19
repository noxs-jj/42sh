/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_detail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:49:50 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/19 15:59:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** cut the string with '|', '>', '<' or ">>"
** save the first part and return the second
** TEST OK vjacquie
*/

static char	*lx_op(char *str, t_cmd *op, int n)
{
	char	*tmp;
	char	*cpy;
	int		start;

	start = 0;
	if (n == 1)
		start = lx_pos_op(str, "|");
	else if (n == 3)
		start = lx_pos_op(str, ">");
	else if (n == 4)
		start = lx_pos_op(str, ">>");
	else if (n == 2)
		start = lx_pos_op(str, "<");
	tmp = ft_strsub(str, 0, start);
	lx_add_more(op, lx_new_more(tmp, n));
	if (n == 4)
		cpy = ft_strsub(str, start + 2, ft_strlen(str) - start);
	else
		cpy = ft_strsub(str, start + 1, ft_strlen(str) - start);
	free(str);
	return (cpy);
}

/*
** main function for the detail lexing
** TEST OK vjacquie
*/

void		lx_detail(t_cmd *op)
{
	char	*str;

	str = ft_strdup(op->cmd);
	while (lx_is_op(str) > 0)
	{
		str = lx_op(str, op, lx_is_op(str));
	}
	lx_add_more(op, lx_new_more(str, 0));
}
