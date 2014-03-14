/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:58:34 by scohen            #+#    #+#             */
/*   Updated: 2014/03/14 16:44:57 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	build_cd(t_data *d)
{
	char	**av;

	ft_putstr_fd(d->toexec, 2);
	ft_replace('\t', ' ', d->toexec);
	av = ft_strsplit(d->toexec, ' ');
	ft_putstr_fd(av[0], 2);
	ft_putstr_fd(av[1], 2);
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
				if (ft_strcmp(av[1], "..") == 0)
					cd_double_dot(d);
				else
					cd_change_pwd(d, av[1]);
			}
		}
	}
	if (av[1] == NULL)
		cd_only(d, av[1]);
}
