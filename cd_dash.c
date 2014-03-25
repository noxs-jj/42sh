/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:56 by scohen            #+#    #+#             */
/*   Updated: 2014/03/19 12:52:03 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_dash(t_data *d, char *name)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_getenv("PWD", d->cenv);
	oldpwd = ft_getenv("OLDPWD", d->cenv);
	if (chdir(oldpwd) == -1)
		cd_error(name);
	else
	{
		ft_putendl(oldpwd);
		ft_setenv(d, "PWD", oldpwd);
		ft_setenv(d, "OLDPWD", pwd);
	}
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
	if (oldpwd != NULL)
		ft_memdel((void **)&oldpwd);
}
