/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 11:23:28 by scohen            #+#    #+#             */
/*   Updated: 2014/02/26 13:45:53 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			env_copy(char **environ, t_data *d)
{
	int			i;
	int			y;
	char		*tmp;

	d->c_env = (char **)malloc(sizeof(char *) * env_tabheight(environ));
	if (d->c_env == NULL)
	{
		WR(2, "Malloc error on env_copy\n");
		_exit(1);
	}
	y = 0;
	while (y != env_tabheight(environ))
	{
		tmp = ft_strnew(ft_strlen(environ[y]) + 1);
		i = 0;
		while (environ[y][i] != '\0')
		{
			tmp[i] = environ[y][i];
			i++;
		}
		tmp[i] = '\0';
		d->c_env[y] = tmp;
		y++;
	}
	d->c_env[y] = NULL;
}
