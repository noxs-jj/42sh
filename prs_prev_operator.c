/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_prev_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:32:48 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:27 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if previous chainlink is a '|'
** else if previous chainlink is a '<'
** if previous chainlink is a '>'
** if previous chainlink is a '>>'
*/

void	prev_operator(t_data *d, t_more *link)
{
	if (link->prev->end == 1)
		recurse_pipe(d, link->prev, 0);
	else if (link->prev->end == 2)
		recurse_left(d, link->prev);
	else if (link->prev->end == 3)
		ft_putstr_fd("Ambiguous output redirect. (prev_operator)\n", 2);
	else if (link->prev->end == 4)
		ft_putstr_fd("Ambiguous output redirect. (prev_operator)\n", 2);
	else
		ft_putstr_fd("Operator error (prs_parser else if)\n", 2);
}
