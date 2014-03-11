/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:04:07 by scohen            #+#    #+#             */
/*   Updated: 2014/03/11 18:04:08 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_change_pwd(t_data *d, char *add)
{
	char	*pwd;
	char	*fj;
	char	*sj;

	pwd = ft_getenv("PWD", d->env);
	ft_setenv(d, "OLDPWD", pwd);
	fj = ft_strjoin(pwd, "/");
	sj = ft_strjoin(fj, add);
	free(pwd);
	free(fj);	
	ft_setenv(d, "PWD", sj);
	free(sj);
}