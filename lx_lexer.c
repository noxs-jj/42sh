/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:50:08 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/05 15:04:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** main function for lexing
** TEST OK vjacquie
*/

void	lx_lexer(char *line, t_data *d)
{
	t_cmd	*tmp;

	lx_lex_line(line, d);
	tmp = d->lst_line;
	while (tmp != NULL)
	{
		lx_detail(tmp);
		tmp = tmp->next;
	}
}
