/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:27:25 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/18 11:25:59 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Do pipe operator, redirect to file fd if fd != 0
** TEST OK jmoiroux
*/

static void	fils(t_data *d, t_more *link, int fd, int pfd[2]);

int			recurse_pipe(t_data *d, t_more *link, int fd)
{
	int	father;
	int	pfd[2];

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
		fils(d, link, fd, pfd);
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (link->prev != NULL)
			prev_operator(d, link);
	}
	dup2(0, 1);
	return (1);
}

static void	fils(t_data *d, t_more *link, int fd, int pfd[2])
{
		d->toexec = link->str;
		close(pfd[1]);
		if (link->prev != NULL)
			dup2(pfd[0], 0);
		close(pfd[0]);
		if (fd != 0)
			dup2(fd, 1);
		exe_build_system(d);
		_exit(1);
}
