/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:15:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/25 16:45:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** do execve, check if bin is present, check acces
** TEST OK jmoiroux
*/

static int	exe_check_exist(char *tmp)
{
	if (is_dir(tmp))
		return (ERR_ISDIR);
	if (access(tmp, F_OK) != 0)
		return (ERR_NOEXIST);
	if (access(tmp, X_OK) != 0)
		return (ERR_DENIED);
	return (SUCCESS);
}

static void	exe_search_exe2(t_data *d, t_searchexe *s)
{
	s->var = ft_getenv("PATH", d->env);
	s->i = 0;
	s->tmp = NULL;
	if (s->var == NULL)
	{
		WR(2, "Command not found\n");
		_exit(1);
	}
	s->path = ft_strsplit(s->var, ':');
	free(s->var);
}

static char	*exe_search_exe(t_data *d)
{
	t_searchexe	s;

	exe_search_exe2(d, &s);
	while ((s.path)[s.i])
	{
		s.tofree = s.tmp;
		s.tmp = ft_strnew(ft_strlen(s.path[s.i]) + 1 + ft_strlen(d->argv[0]));
		ft_strcat(s.tmp, (s.path)[s.i]);
		ft_strcat(s.tmp, "/");
		ft_strcat(s.tmp, d->argv[0]);
		if (exe_check_exist(s.tmp) == SUCCESS)
		{
			ft_strdel(&d->argv[0]);
			return (s.tmp);
		}
		ft_strdel(&(s.tofree));
		++(s.i);
	}
	ft_strdel(&(s.tmp));
	return (NULL);
}

int			exe_execve(t_data *d)
{
	int			error;

	ft_replace('\t', ' ', d->toexec);
	d->argv = ft_strsplit(d->toexec, ' ');
	error = SUCCESS;
	if (!is_dotslash(d->argv[0]) && !is_absolute(d->argv[0]))
		d->argv[0] = exe_search_exe(d);
	else if ((error = exe_check_exist(d->argv[0])) != SUCCESS)
	{
		if (error == ERR_ISDIR)
			WR(2, "is a directory\n");
		if (error == ERR_NOEXIST)
			WR(2, "does not exist\n");
		if (error == ERR_DENIED)
			WR(2, "access denied\n");
	}
	if (d->argv != NULL && d->argv[0] != NULL && error == SUCCESS)
	{
		execve(d->argv[0], d->argv, d->env);
		WR(2, "Could not execute");
	}
	else if (d->argv[0] == NULL)
		WR(2, "Command not found\n");
	_exit(1);
	return (-1);
}
