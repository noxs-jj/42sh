/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_envdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:31 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/14 12:34:59 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// static void	ft_envdel(char ***env)
// {
// 	char	***p;

// 	p = env;
// 	while (**env)
// 	{
// 		free(**env);
// 		**env = NULL;
// 		++*env;
// 	}
// 	free(**p);
// 	*p = NULL;
// }

void		env_envdel(t_data *d)
{
	int		i;

	i = 0;
	while (d && d->env && d->env[i])
	{
		if (d && d->env && d->env[i])
			ft_memdel((void **)&d->env[i]);
		i++;
	}
	if (d && d->env)
		ft_memdel((void **)&d->env);
}
