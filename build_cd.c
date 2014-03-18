/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:58:34 by scohen            #+#    #+#             */
/*   Updated: 2014/03/18 13:18:10 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	build_cd(t_data *d)
{
	char	**av;

	ft_replace('\t', ' ', d->toexec);
	av = ft_strsplit(d->toexec, ' ');
	if (av[1] != NULL && ft_strcmp(av[1], ".") != 0)
	{
		if (ft_strcmp(av[1], "-") == 0)
			cd_dash(d, av[1]);
		else
		{
			if (chdir(av[1]) == -1)
				cd_error(av[1]);
			else
			{
				if (ft_strncmp(av[1], "..", 2) == 0 
					&& (av[1][2] == '/' || av[1][2] == '\0'))
					cd_double_dot(d, av[1]);
				else
					cd_change_pwd(d, av[1]);
			}
		}
	}
	if (av[1] == NULL)
		cd_only(d, av[1]);
}
