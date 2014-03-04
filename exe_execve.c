/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:15:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 14:38:55 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

//static char	**exe_make_argv(t_data *d);

static int	exe_check_exist(char *cmd)
{
	if (is_dir(cmd))
		return (ERR_ISDIR);
	if (access(cmd, F_OK) != 0)
		return (ERR_NOEXIST);
	if (access(cmd, X_OK) != 0)
		return (ERR_DENIED);
	return (SUCCESS);
}

static char	*exe_search_exe(t_data *d)
{
	char		**path;
	char		*var;
	char		*found;
	char		*tofree;
	size_t		i;

	i = 0;
	var = ft_getenv("PATH", d->env);
	path = ft_strsplit(var, ':');
	free(var);
	found = NULL;
	while (path[i])
	{
		tofree = found;
		found = ft_strnew(ft_strlen(path[i]) + 1 + ft_strlen(d->argv[0]));
		ft_strcat(found, path[i]);
		ft_strcat(found, "/");
		ft_strcat(found, d->argv[0]);
		if (exe_check_exist(found) == SUCCESS)
			return (found);
		ft_strdel(&tofree);
		++i;
	}
	return (NULL);
}

int			exe_execve(t_data *d)
{
	int			error;

	d->argv = ft_strsplit(d->line, ' ');
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
	if (d->argv != NULL)
		execve(d->argv[0], d->argv, d->env);
	return (-1);
}
