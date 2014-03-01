/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_envdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:31 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:17:48 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_envdel(char ***env)
{
	char	***p;

	p = env;
	while (**env)
	{
		free(**env);
		**env = NULL;
		++*env;
	}
	free(**p);
	*p = NULL;
}

void		env_envdel(t_data *d)
{
	ft_envdel(&d->env);
}
