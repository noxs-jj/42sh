/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 17:24:23 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prs_operator(t_data *d, t_more *link);

/*
** main parser, check chaininglist and lunch function operator
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
** TEST OK jmoiroux
*/

void	prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;
	t_more	*tmpmore;
	int		father;

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL)
	{
		tmpmore = tmpcmd->more;
		while (tmpmore->next != NULL)
			tmpmore = tmpmore->next;
		if (tmpmore->prev != NULL)
			prs_operator(d, tmpmore);
		else
		{
			if ((father = fork()) < 0)
				ft_exit(d, "Fork error (prs_parser)\n");
			if (father == 0)
			{
				d->toexec = tmpmore->str;
				exe_build_system(d);
				_exit(0);
			}
			else
				wait(NULL);
		}
		tmpcmd = tmpcmd->next;
	}
}

static void	prs_operator(t_data *d, t_more *link)
{
	if (link->prev->end == 1)
		recurse_pipe(d, link, 0);
	else if (link->prev->end == 2)
		recurse_left(d, link);
	else if (link->prev->end == 3)
		recurse_right(d, link);
	else if (link->prev->end == 4)
		recurse_rright(d, link);
	else
		ft_exit(d, "Operator error (prs_parser else if)\n");
}
