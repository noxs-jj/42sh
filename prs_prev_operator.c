/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_prev_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:32:48 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/17 15:58:46 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if previous chainlink is a '|'
** else if previous chainlink is a '<'
** if previous chainlink is a '>'
** if previous chainlink is a '>>'
** TEST OK jmoiroux
*/

void	prev_operator(t_data *d, t_more *link)
{
	if (link->prev->end == 1)
		recurse_pipe(d, link->prev, 0);
	else if (link->prev->end == 2)
		recurse_left(d, link->prev);
	else if (link->prev->end == 3)
		WR(2, "Ambiguous output redirect. (prev_operator)\n");
	else if (link->prev->end == 4)
		WR(2, "Ambiguous output redirect. (prev_operator)\n");
	else
		WR(2, "Operator error (prs_parser else if)\n");
}
