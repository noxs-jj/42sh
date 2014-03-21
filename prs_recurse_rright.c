/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_rright.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:29:00 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/21 13:02:31 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	recurse_rrightfork(t_data *d, int father, t_more *link, int fd);

/*
** Do double right arrow
** TEST OK jmoiroux
*/

int			recurse_rright(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	father = -1;
	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDWR | O_CREAT | O_APPEND, 0777)) == -1)
	{
		WR(2, "File open error (recurse_rright)\n");
		ft_memdel((void **)&tmp);
		return (-1);
	}
	ft_memdel((void **)&tmp);
	if (recurse_rrightfork(d, father, link, fd) == -1)
		return (-1);
	return (1);
}

static int	recurse_rrightfork(t_data *d, int father, t_more *link, int fd)
{
	if ((father = fork()) < 0)
	{
		WR(2, "Fork() error (recurse_rright)\n");
		return (-1);
	}
	if (father == 0)
	{
		d->toexec = link->prev->str;
		if (link->prev && link->prev->prev)
			recurse_pipe(d, link->prev, fd);
		else
		{
			dup2(fd, 1);
			exe_build_system(d);
		}
		_exit(0);
	}
	return (-1);
}
