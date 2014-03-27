/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_only.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:43 by scohen            #+#    #+#             */
/*   Updated: 2014/03/27 15:22:48 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if 'cd' only
*/

void	cd_only(t_data *d, char *name)
{
	char	*home;
	char	*pwd;

	home = ft_getenv("HOME", d->cenv);
	pwd = ft_getenv("PWD", d->cenv);
	if (chdir(home) == -1)
		cd_error("Home directory");
	else
	{
		ft_setenv(d, "OLDPWD", pwd);
		ft_setenv(d, "PWD", home);
	}
	if (home != NULL)
		ft_memdel((void **)&home);
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
	(void)name;
}
