/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:24:50 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/14 12:34:26 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	recurse_right(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
		ft_exit(d, "File open error (recurse_right)\n");
	ft_memdel((void **)&tmp);
	if ((father = fork()) < 0)
		ft_exit(d, "Fork() error (recurse_right)\n");
	//d->toexec = link->prev->str;
	if (father == 0)
	{
		d->toexec = link->prev->str;
		if (link->prev && link->prev->prev)
			recurse_pipe(d, link->prev, fd);
		else
		{
			dup2(fd, 1);
			exe_execve(d);
		}
		_exit(0);
	}
	else
		wait(NULL);
}
