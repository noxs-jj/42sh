/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:27:25 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 12:34:23 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	recurse_pipe(t_data *d, t_more *link, int fd)
{
	int	father;
	int	pfd[2];

	if (fd == 0)
		fd = d->backup[0];
	if (pipe(pfd) == -1)
		ft_exit(d, "Pipe error (recurse_pipe)");
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_pipe)");
	if (father == 0) /* son */
	{
		d->toexec = link->str;
		close(pfd[1]);
		dup2(pfd[0], 0);
		if (fd != 0)
			dup2(fd, 1);
		close(pfd[0]);
		exe_execve(d);
		_exit(0);
	}
	else /* father */
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		//close(pfd[1]);
		if (link->prev != NULL) /* if previous cmd present */
			prev_operator(d, link);
	}
}
