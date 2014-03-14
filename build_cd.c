/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:58:34 by scohen            #+#    #+#             */
/*   Updated: 2014/03/11 13:58:36 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	build_cd(t_data *d)
{
	char	**av;

	ft_replace('\t', ' ', d->line);
	av = ft_strsplit(d->line, ' ');
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
	if (av[1] == NULL) /* If cd only */
		cd_only(d, av[1]);
}