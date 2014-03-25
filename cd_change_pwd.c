/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:04:07 by scohen            #+#    #+#             */
/*   Updated: 2014/03/17 12:34:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_change_pwd(t_data *d, char *add)
{
	char	*pwd;
	char	*fj;
	char	*sj;

	pwd = ft_getenv("PWD", d->cenv);
	ft_setenv(d, "OLDPWD", pwd);
	fj = ft_strjoin(pwd, "/");
	sj = ft_strjoin(fj, add);
	ft_setenv(d, "PWD", sj);
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
	if (fj != NULL)
		ft_memdel((void **)&fj);
	if (sj != NULL)
		ft_memdel((void **)&sj);
}
