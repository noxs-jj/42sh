/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_prev_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:32:48 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 12:34:21 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	prev_operator(t_data *d, t_more *link)
{
	if (link->prev->end == 1) /* if previous chainlink is a '|' */
		recurse_pipe(d, link->prev, 0);
	else if (link->prev->end == 2) /* if previous chainlink is a '<' */
		recurse_left(d, link->prev);
	else if (link->prev->end == 3) /* if previous chainlink is a '>' */
		ft_exit(d, "Ambiguous output redirect. (prev_operator)\n");
	else if (link->prev->end == 4) /* if previous chainlink is a '>>' */
		ft_exit(d, "Ambiguous output redirect. (prev_operator)\n");
	else
		ft_exit(d, "Operator error (prs_parser else if)\n");
}
