/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/25 23:42:35 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** main parser, check chaininglist and lunch function operator
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
** TEST OK jmoiroux
*/

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
		_exit(1);
	}
	return (1);
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

static void	prs_parser2(t_data *d, t_cmd *tmpcmd)
{
	t_more	*tmpmore;

	tmpmore = tmpcmd->more;
	while (tmpmore->next != NULL)
		tmpmore = tmpmore->next;
	if (tmpmore->prev != NULL)
		prs_operator(d, tmpmore);
	else
		prs_parseralone(d, tmpmore);
}

void		prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL)
	{
		d->current = tmpcmd;
		if (tmpcmd->more != NULL && tmpcmd->more->str != NULL
			&& tmpcmd->more->next == NULL && tmpcmd->more->str[0] != '\0'
			&& check_cmdparam(d, tmpcmd->more) == 1)
			;
		else
			prs_parser2(d, tmpcmd);
		while (waitpid(-1, &(d->current->exedone), WUNTRACED) > 0)
			;
		while (tmpcmd && d->current->exedone == 0 && tmpcmd->i == 2)
			tmpcmd = tmpcmd->next;
		while (tmpcmd && d->current->exedone != 0 && tmpcmd->i == 1)
			tmpcmd = tmpcmd->next;
		if (tmpcmd)
			tmpcmd = tmpcmd->next;
	}
}
