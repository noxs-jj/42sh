/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmdparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 13:33:48 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/25 23:32:53 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** check incoming linkcmd, execute if
** TEST OK jmoiroux
*/

static int	check_cmdparam2(t_data *d, char *tmp)
{
	if (ft_strncmp("cd", tmp, ft_strlen("cd")) == 0)
	{
		d->toexec = tmp;
		build_cd(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	if (ft_strncmp("setenv", tmp, ft_strlen("setenv")) == 0)
	{
		d->toexec = tmp;
		build_setenv(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	if (ft_strncmp("unsetenv", tmp, ft_strlen("unsetenv")) == 0)
	{
		d->toexec = tmp;
		build_unsetenv(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	return (0);
}

static int	check_cmdparam3(t_data *d, char *tmp)
{
	if (ft_strncmp("exit", tmp, ft_strlen("exit")) == 0)
	{
		d->toexec = tmp;
		build_exit(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	if (ft_strncmp("echo", tmp, ft_strlen("echo")) == 0)
	{
		d->toexec = tmp;
		build_echo(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	if (ft_strncmp("env", tmp, ft_strlen("env")) == 0)
	{
		d->toexec = tmp;
		env_printenv(d);
		ft_memdel((void **)&tmp);
		return (1);
	}
	return (0);
}

int			check_cmdparam(t_data *d, t_more *link)
{
	char	*tmp;

	if (link->str != NULL)
	{
		tmp = ft_strtrim(link->str);
		if (check_cmdparam2(d, tmp) == 1)
			return (1);
		if (check_cmdparam3(d, tmp) == 1)
			return (1);
		ft_memdel((void **)&tmp);
	}
	return (0);
}
