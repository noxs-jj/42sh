/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:59:36 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/14 16:27:42 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** open link and dup2 it on prev link cmd
** TEST OK jmoiroux
*/

int	recurse_left(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDONLY)) == -1)
		ft_exit(d, "File open error (recurse_left)\n");
	if (link->prev->str == NULL)
	{
		WR(2, "< usage: [commandline < file]\n");
		return (-1);
	}
	ft_memdel((void **)&tmp);
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_left)\n");
	if (father == 0)
	{
		dup2(fd, 0);
		d->toexec = link->prev->str;
		exe_build_system(d);
		_exit(-1);
	}
	else
		wait(NULL);
	return (1);
}
