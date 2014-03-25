/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:24:50 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/25 12:29:56 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	recurse_rightfork(t_data *d, int father, t_more *link, int fd);
static void	recurse_right_error(void);

/*
** do right arrow
** TEST OK jmoiroux
*/

int			recurse_right(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	father = -1;
	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
	{
		WR(2, "File open error > (recurse_right)\n");
		ft_memdel((void **)&tmp);
		return (-1);
	}
	ft_memdel((void **)&tmp);
	if (recurse_rightfork(d, father, link, fd) == -1)
		return (-1);
	return (1);
}

static int	recurse_rightfork(t_data *d, int father, t_more *link, int fd)
{
	if ((father = fork()) < 0)
	{
		WR(2, "Fork() error > (recurse_right)\n");
		return (-1);
	}
	if (father == 0)
	{
		d->toexec = link->prev->str;
		if (link->prev != NULL && link->prev->prev != NULL
				&& link->prev->prev->end == 1)
			recurse_pipe(d, link->prev, fd);
		else if (link->prev != NULL && link->prev->prev != NULL
				&& (link->prev->prev->end == 2
				|| link->prev->prev->end == 3))
			recurse_right_error();
		else
		{
			dup2(fd, 1);
			exe_build_system(d);
		}
		_exit(1);
	}
	return (1);
}

static void	recurse_right_error(void)
{
	WR(2, "Operator: '>' usage: 'executable > file'\n");
	WR(2, "or 'executable | executable > file' only\n");
}
