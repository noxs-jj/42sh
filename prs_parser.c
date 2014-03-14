/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 12:37:01 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/* typedef struct		s_more
**{
**	char			*str;
**	int				end;
**	struct s_more	*next;
**	struct s_more	*prev;
**}					t_more;
**
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
*/

static void	prs_operator(t_data *d, t_more *link);

void	prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;
	t_more	*tmpmore;
	int		father;

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL)
	{ /* run the first chainlink (read from left to right) */
		tmpmore = tmpcmd->more; /* take full str cmdline */
		while (tmpmore->next != NULL) /* go to last cmd (full right) */
			tmpmore = tmpmore->next;
		if (tmpmore->prev != NULL) /* if previous cmd present */
			prs_operator(d, tmpmore);
		else /* if cmd is alone exec it */
		{
			if ((father = fork()) < 0)
				ft_exit(d, "Fork error (prs_parser)\n");
			if (father == 0) /* son */
			{ /* toexec take value of chainlink str */
				d->toexec = tmpmore->str;
				exe_execve(d);
				_exit(0);
			}
			else /* father */
			{
				wait(NULL);
				return ;
			}
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

void	recurse_left(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
	ft_printf("left\n");
}
