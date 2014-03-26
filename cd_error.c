/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:25 by scohen            #+#    #+#             */
/*   Updated: 2014/03/26 12:03:20 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	cd_error2(char *name, t_data *d)
{
	ft_putstr_fd("42sh : ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": is not a directory.\n", 2);
	d->current->exedone = 1;
}

int			cd_error(char *name)
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
		ft_putstr_fd("42sh : ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": directory not found.\n", 2);
		d->current->exedone = 1;
		return (-1);
	}
	if (access(name, X_OK) == -1)
	{
		ft_putstr_fd("42sh : ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": %s : permission denied.\n", 2);
		d->current->exedone = 1;
		return (-1);
	}
	return (0);
}
