/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:15:04 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/11 12:09:20 by jmoiroux         ###   ########.fr       */
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
	while (tmpcmd != NULL)
	{ /* run the first chainlink (read from left to right) */
		tmpmore = tmpcmd->more; /* take full str cmdline */
		while (tmpmore->next != NULL) /* go to last cmd (full right) */
			tmpmore = tmpmore->next;
		if (tmpmore->prev != NULL) /* if previous cmd present */
		{
			if (tmpmore->prev->end == 1)
			{ /* if previous chainlink is a '|' */
				recurse_pipe(d, tmpmore);
				return ;
			}
			else if (tmpmore->prev->end == 2)
			{ /* if previous chainlink is a '<' */
				recurse_left(d, tmpmore);
				return ;
			}
			else if (tmpmore->prev->end == 3)
			{ /* if previous chainlink is a '>' */
				recurse_right(d, tmpmore);
				return ;
			}
			else if (tmpmore->prev->end == 4)
			{ /* if previous chainlink is a '>>' */
				recurse_rright(d, tmpmore);
				return ;
			}
			else
				ft_exit(d, "Operator error (prs_parser else if)\n");
		}
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

void	prev_operator(t_data *d, t_more *link)
{
	if (link->prev->end == 1) /* if previous chainlink is a '|' */
	{
		recurse_pipe(d, link->prev);
		return ;
	}
	else if (link->prev->end == 2) /* if previous chainlink is a '<' */
	{
		recurse_left(d, link->prev);
		return ;
	}
	else if (link->prev->end == 3) /* if previous chainlink is a '>' */
	{
		recurse_right(d, link->prev);
		return ;
	}
	else if (link->prev->end == 4) /* if previous chainlink is a '>>' */
	{
		recurse_rright(d, link->prev);
		return ;
	}
	else
		ft_exit(d, "Operator error (prs_parser else if)\n");
}

void	recurse_pipe(t_data *d, t_more *link)
{
	int	father;
	int	pfd[2];

	if (pipe(pfd) == -1)
		ft_exit(d, "Pipe error (recurse_pipe)");
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_pipe)");
	if (father == 0) /* son */
	{
		d->toexec = link->str;
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		exe_execve(d);
		_exit(0);
	}
	else /* father */
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (link->prev != NULL) /* if previous cmd present */
			prev_operator(d, link);
	}
}

void	recurse_right(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	tmp = ft_strtrim(link->str);
	free(tmp);
	if ((fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1)
		ft_exit(d, "File open error (recurse_right)\n");
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_right)\n");
	d->toexec = link->prev->str;
	if (father == 0)
	{
		dup2(fd, 1);
		exe_execve(d);
		_exit(0);
	}
	else
	{
		wait(NULL);
	}
}

void	recurse_left(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
	ft_printf("left\n");
}

void	recurse_rright(t_data *d, t_more *link)
{
	(void)d;
	(void)link;
	ft_printf("Rright\n");
}
