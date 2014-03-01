/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:29:45 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/01 16:59:50 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	build_setenv(t_data *d)
{
	printf("--------build setenv--------\n");
	char **tmp;

	tmp = ft_strsplit(d->line, ' ');
	if (tmp == NULL)
		ft_exit(d, "split error (build_env)\n");
	d->varenv = tmp[1];
	d->valenv = tmp[2];

	env_setenv(d);
	//ft_memdel((void **)&tmp[0]);
	//ft_memdel((void **)&tmp);
}
