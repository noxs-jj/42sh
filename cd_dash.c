/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:56 by scohen            #+#    #+#             */
/*   Updated: 2014/03/17 12:24:53 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_dash(t_data *d, char *name)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_getenv("PWD", d->env);
	oldpwd = ft_getenv("OLDPWD", d->env);
	if (chdir(oldpwd) == -1)
		cd_error(name);
	else
	{
		ft_setenv(d, "PWD", oldpwd);
		ft_setenv(d, "OLDPWD", pwd);
	}
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
	if (pwd != NULL)
		ft_memdel((void **)&oldpwd);
}
