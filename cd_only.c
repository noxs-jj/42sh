/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_only.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:43 by scohen            #+#    #+#             */
/*   Updated: 2014/03/17 11:41:22 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if 'cd' only
** TEST OK jmoiroux
*/

void	cd_only(t_data *d, char *name)
{
	char	*home;
	char	*pwd;

	home = ft_getenv("HOME", d->env);
	pwd = ft_getenv("PWD", d->env);
	if (chdir(home) == -1)
		cd_error(name);
	else
	{
		ft_setenv(d, "OLDPWD", pwd);
		ft_setenv(d, "PWD", home);
	}
	if (home != NULL)
		ft_memdel((void **)&home);
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
}
