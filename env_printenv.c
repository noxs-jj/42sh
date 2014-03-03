/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_printenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/03 12:55:12 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** print envcopy
** TEST OK jmoiroux
*/

void	env_printenv(t_data *d)
{
	int		i;

	i = 0;
	printf("%s\n", "printenv");
	while (d->env[i] != NULL && d->env[i][0] != '\0')
	{
		ft_putendl(d->env[i]);
		++i;
	}
}