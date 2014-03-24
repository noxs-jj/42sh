/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:25 by scohen            #+#    #+#             */
/*   Updated: 2014/03/24 15:34:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	cd_error2(char *name, t_data *d);

int		cd_error(char *name)
{
	t_data	*d;

	d = dataptr(NULL);
	if (is_dir(name) == 0)
	{
		cd_error2(name, d);
		return (-1);
	}
	if (access(name, F_OK) == -1)
	{
		WR(2, "42sh : ");
		ft_putstr_fd(name, 2);
		WR(2, ": directory not found.\n");
		d->current->exedone = 1;
		return (-1);
	}
	if (access(name, X_OK) == -1)
	{
		WR(2, "42sh : ");
		ft_putstr_fd(name, 2);
		WR(2, ": %s : permission denied.\n");
		d->current->exedone = 1;
		return (-1);
	}
	return (0);
}

static void	cd_error2(char *name, t_data *d)
{
	WR(2, "42sh : ");
	ft_putstr_fd(name, 2);
	WR(2, ": is not a directory.\n");
	d->current->exedone = 1;
}
