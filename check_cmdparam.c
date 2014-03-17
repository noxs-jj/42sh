/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmdparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 13:33:48 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/17 13:08:19 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	param_exit(t_data *d, char *tmp);
static int	param_unsetenv(t_data *d, char *tmp);
static int	param_setenv(t_data *d, char *tmp);
static int	param_cd(t_data *d, char *tmp);

/*
** check incoming linkcmd, execute if
** TEST OK jmoiroux
*/

int			check_cmdparam(t_data *d, t_more *link)
{
	char	*tmp;

	if (link->str != NULL)
	{
		tmp = ft_strtrim(link->str);
		if (ft_strnequ("cd", tmp, ft_strlen("cd")) == 1)
			return (param_cd(d, tmp));
		else if (ft_strnequ("setenv", tmp, ft_strlen("setenv")) == 1)
			return (param_setenv(d, tmp));
		else if (ft_strnequ("unsetenv", tmp, ft_strlen("unsetenv")) == 1)
			return (param_unsetenv(d, tmp));
		else if (ft_strnequ("exit", tmp, ft_strlen("exit")) == 1)
			return (param_exit(d, tmp));
		else
		{
			ft_memdel((void **)&tmp);
			return (0);
		}
	}
	return (0);
}

static int	param_cd(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_cd(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_setenv(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_setenv(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_unsetenv(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_unsetenv(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_exit(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_exit(d);
	ft_memdel((void **)&tmp);
	return (1);
}
