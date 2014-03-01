/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_printenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:42:01 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_printenv(char **env)
{
	while (*env && **env)
	{
		ft_putendl(*env);
		++env;
	}
}

void	env_printenv(t_data *d)
{
	ft_printenv(d->env);
}
