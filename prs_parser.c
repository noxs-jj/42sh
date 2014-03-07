/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/05 15:08:21 by vjacquie         ###   ########.fr       */
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

void	recurse_pipe(t_data *d, t_more *link);
void	recurse_left(t_data *d, t_more *link);
void	recurse_right(t_data *d, t_more *link);
void	recurse_rright(t_data *d, t_more *link);

void	prs_parser(t_data *d)
{
	t_cmd	*tmpcmd;
	t_more	*tmpmore;
	int		father; /* a remettre au bonne endroit NORME */

	tmpcmd = d->lst_line;
	while (tmpcmd != NULL) /* run the first chainlink (read from left to right) */
	{
		tmpmore = tmpcmd->more; /* take full str cmdline */
		while (tmpmore->next != NULL) /* go to last cmd (full right) */
			tmpmore = tmpmore->next;
		if (tmpmore->prev != NULL) /* if previous cmd present */
		{
			if (tmpmore->prev->end == 1) /* if previous chainlink is a '|' */
				recurse_pipe(d, tmpmore->prev);
			else if (tmpmore->prev->end == 2) /* if previous chainlink is a '<' */
				recurse_left(d, tmpmore->prev);
			else if (tmpmore->prev->end == 3) /* if previous chainlink is a '>' */
				recurse_right(d, tmpmore->prev);
			else if (tmpmore->prev->end == 4) /* if previous chainlink is a '>>' */
				recurse_rright(d, tmpmore->prev);
			else
				ft_exit(d, "Operator error (prs_parser else if)\n");
		}
		else /* if cmd is alone exec it */
		{
			ft_printf("else fork() execve\n");
			if ((father = fork()) < 0)
				ft_exit(d, "Fork error (prs_parser)\n");
			if (father == 0) /* son */
			{
				d->toexec = tmpmore->str; /*toexec take value of chainlink str */
				exe_execve(d);
				_exit(0);
			}
			else /* father */
				wait(NULL);
		}
		tmpcmd = tmpcmd->next;
	}
}

void	recurse_pipe(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
	ft_printf("pipe\n");
}

void	recurse_left(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
		ft_printf("left\n");
}

void	recurse_right(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
		ft_printf("right\n");
}

void	recurse_rright(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
		ft_printf("Rright\n");
}