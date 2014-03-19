/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/19 15:48:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prs_operator(t_data *d, t_more *link);
static int	prs_parseralone(t_data *d, t_more *tmpmore);
static void	prs_parser2(t_data *d, t_cmd *tmpcmd);

/*
** main parser, check chaininglist and lunch function operator
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
** TEST OK jmoiroux
*/

void		prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL)
	{
		if (tmpcmd->more != NULL && tmpcmd->more->str != NULL
			&& tmpcmd->more->str[0] != '\0'
			&& check_cmdparam(d, tmpcmd->more) == 1)
			;
		else
			prs_parser2(d, tmpcmd);
		while (waitpid(WAIT_ANY, &tmpcmd->exedone, WNOHANG) != -1)
			;
		if (tmpcmd->exedone == 0 && tmpcmd->i == 2)
			tmpcmd = tmpcmd->next;
		else if (tmpcmd->exedone != 0 && tmpcmd->i == 1)
			tmpcmd = tmpcmd->next;
		tmpcmd = tmpcmd->next;
	}
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
		_exit(1);
	}
	else
		wait(NULL);
	return (1);
}
