/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:59:36 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** open link and dup2 it on prev link cmd
*/

static int	recurse_leftfork(t_data *d, int father, int fd, t_more *link)
{
	if ((father = fork()) < 0)
	{
		ft_putstr_fd("Fork() error (recurse_left)\n", 2);
		return (-1);
	}
	if (father == 0)
	{
		dup2(fd, 0);
		d->toexec = link->prev->str;
		exe_build_system(d);
		_exit(1);
	}
	return (1);
}

static int	recurse_leftalone(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	father = -1;
	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDONLY)) == -1)
	{
		ft_putstr_fd("File open error (recurse_left)\n", 2);
		ft_memdel((void **)&tmp);
		return (-1);
	}
	if (link->prev != NULL && link->prev->str == NULL)
	{
		ft_putstr_fd("Operator: < usage: 'executable < file' only\n", 2);
		ft_memdel((void **)&tmp);
		return (-1);
	}
	ft_memdel((void **)&tmp);
	if (recurse_leftfork(d, father, fd, link) == -1)
		return (-1);
	return (1);
}

int			recurse_left(t_data *d, t_more *link)
{
	if (link->next != NULL
		|| (link->prev != NULL && ft_strlen(link->prev->str) == 0))
	{
		ft_putstr_fd("Operator: < usage: 'executable < file' only\n", 2);
		return (-1);
	}
	else
	{
		if (recurse_leftalone(d, link) == -1)
			return (-1);
	}
	return (1);
}
