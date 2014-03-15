/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:27:25 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/15 15:04:49 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Do pipe operator, redirect to file fd if fd != 0
** TEST OK jmoiroux
*/

int	recurse_pipe(t_data *d, t_more *link, int fd)
{
	int	father;
	int	pfd[2];

	fd = (fd == 0) ? (d->backup[0]) : fd;
	if (pipe(pfd) == -1)
	{
		WR(2, "Pipe error (recurse_pipe)\n");
		return (-1);
	}
	if ((father = fork()) < 0)
	{
		WR(2, "Fork() error (recurse_pipe)\n");
		return (-1);
	}
	if (father == 0)
	{
		d->toexec = link->str;
		close(pfd[1]);
		dup2(pfd[0], 0);
		if (fd != 0)
			dup2(fd, 1);
		close(pfd[0]);
		exe_build_system(d);
		_exit(1);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (link->prev != NULL)
			prev_operator(d, link);
	}
	return (1);
}
