/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:27:25 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 17:13:06 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Do pipe operator, redirect to file fd if fd != 0
** TEST OK jmoiroux
*/

void	recurse_pipe(t_data *d, t_more *link, int fd)
{
	int	father;
	int	pfd[2];

	fd = (fd == 0) ? (d->backup[0]) : fd;
	if (pipe(pfd) == -1)
		ft_exit(d, "Pipe error (recurse_pipe)");
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_pipe)");
	if (father == 0)
	{
		d->toexec = link->str;
		close(pfd[1]);
		dup2(pfd[0], 0);
		if (fd != 0)
		{
			dup2(fd, 1);
			close(fd);
		}
		close(pfd[0]);
		exe_build_system(d);
		_exit(0);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (link->prev != NULL)
			prev_operator(d, link);
	}
}
