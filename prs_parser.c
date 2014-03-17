/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/17 17:54:19 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prs_operator(t_data *d, t_more *link);
static int	prs_parseralone(t_data *d, t_more *tmpmore);

/*
** main parser, check chaininglist and lunch function operator
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
** TEST OK jmoiroux
*/

void		prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;
	t_more	*tmpmore;

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL)
	{
		if (tmpcmd->more != NULL && check_cmdparam(d, tmpcmd->more) == 1)
			;
		else
		{
			tmpmore = tmpcmd->more;
			while (tmpmore->next != NULL)
				tmpmore = tmpmore->next;
			if (tmpmore->prev != NULL)
				prs_operator(d, tmpmore);
			else
				prs_parseralone(d, tmpmore);
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
		WR(2, "Operator error (prs_operator else)\n");
}

static int	prs_parseralone(t_data *d, t_more *tmpmore)
{
	int	father;

	if ((father = fork()) < 0)
	{
		WR(2, "Fork error (prs_parser)\n");
		return (-1);
	}
	if (father == 0)
	{
		d->toexec = tmpmore->str;
		exe_build_system(d);
		return (-1);
		_exit(1);
	}
	else
		wait(NULL);
	return (1);
}
