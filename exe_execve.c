/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:15:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/07 15:50:05 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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

static char	*exe_search_exe(t_data *d)
{
	char		**path;
	char		*var;
	char		*tmp;
	char		*tofree;
	size_t		i;

	i = 0;
	var = ft_getenv("PATH", d->env);
	path = ft_strsplit(var, ':');
	free(var);
	tmp = NULL;
	while (path[i])
	{
		tofree = tmp;
		tmp = ft_strnew(ft_strlen(path[i]) + 1 + ft_strlen(d->argv[0]));
		ft_strcat(tmp, path[i]);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, d->argv[0]);
		if (exe_check_exist(tmp) == SUCCESS)
		{
			ft_strdel(&d->argv[0]);
			return (tmp);
		}
		ft_strdel(&tofree);
		++i;
	}
	ft_strdel(&tmp);
	return (NULL);
}

int			exe_execve(t_data *d)
{
	int			error;

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
		ft_exit(d, "could not execute");
	}
	else if (d->argv[0] == NULL)
		WR(2, "command not found\n");
	return (-1);
}
