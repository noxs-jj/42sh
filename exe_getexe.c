/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_getexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:59:16 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:56:29 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_get_exe2(char *cmd)
{
	if (is_dir(cmd))
		return (ERR_ISDIR);
	if (access(cmd, F_OK) != 0)
		return (ERR_NOEXIST);
	if (access(cmd, X_OK) != 0)
		return (ERR_DENIED);
	return (SUCCESS);
}

static int	ft_get_exe3(char **dst, char **env, char *str)
{
	char			**path;
	char			*tmp;
	char			*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	path = NULL;
	if ((tmp = ft_getenv(str, env), tmp))
		path = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	while (*path)
	{
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		tmp = ft_strjoin(*path, "/");
		tmp2 = ft_strjoin(tmp, str);
		if (access(tmp2, F_OK) == 0)
		{
			if (access(tmp2, X_OK) != 0)
				return ((ft_strdel(dst), ft_strdel(&tmp), ERR_DENIED));
			return ((ft_strdel(dst), *dst = tmp2, SUCCESS));
		}
		++path;
	}
	return (ERR_CMDNOTFOUND);
}

static int	ft_get_exe0(char **dst, char **env, char *cmd)
{
	if (is_absolute(cmd) || is_dotslash(cmd))
		return (ft_get_exe2(cmd));
	if (!*env)
		return (ERR_CMDNOTFOUND);
	return (ft_get_exe3(dst, env, cmd));
}

char		**ft_getexe(char *str, char **env)
{
	char		**exe;

	exe = NULL;
	if (ft_get_exe0(exe, env, str) != SUCCESS)
	{
		ft_putendl_fd("Command not found", 2);
		return (NULL);
	}
	return (exe);
}

char		**env_getexe(t_data *d)
{
	return (ft_getexe(d->line, d->env));
}
