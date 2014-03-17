/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_double_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:03:31 by scohen            #+#    #+#             */
/*   Updated: 2014/03/17 12:24:55 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_double_dot(t_data *d)
{
	char	*pwd;
	int		i;
	int		tmp;

	tmp = 0;
	i = 0;
	pwd = ft_getenv("PWD", d->env);
	ft_setenv(d, "OLDPWD", pwd);
	while (pwd[i] != '\0')
	{
		if (pwd[i] == '/')
			tmp = i;
		i++;
	}
	while (i >= tmp)
		pwd[i--] = '\0';
	ft_setenv(d, "PWD", pwd);
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
}
