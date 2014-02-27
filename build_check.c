/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:53:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/26 15:59:36 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

typedef struct	s_build
{
	char	*str;
	void	(*fptr)(t_data *d, char *str);
}

static const	t_build[] =
{
	{"cd\n", &ft_cd},
	{"cd ", &ft_cd},
	{"env\n ", &env_env},
	{"env ", &env_env},
	{"setenv ", &env_callsetenv},
	{"unsetenv ", &env_callunsetenv},
	{"echo ", &build_echo},
	{"exit ", &ft_cd},
	{"exit\n", &ft_cd},
	{'\0', NULL}
}

/*
** Check what builtin is used et lunch function
** TEST
*/

void			build_check(t_data *d, char *str)
{
	int	i;

	if (str != NULL)
	{
		while (t_build[i].str != '\0')
		{
			if (ft_strcmp(t_build[i].str == 0)
				t_build[i].fptr(d, str);
			i++;
		}
	}
}
