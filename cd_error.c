/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:25 by scohen            #+#    #+#             */
/*   Updated: 2014/03/17 11:47:47 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		cd_error(char *name)
{
	if (is_dir(name) == 0)
	{
		WR(2, "42sh : ");
		ft_putstr_fd(name, 2);
		WR(2, ": is not a directory.\n");
		return (-1);
	}
	if (access(name, F_OK) == -1)
	{
		WR(2, "42sh : ");
		ft_putstr_fd(name, 2);
		WR(2, ": directory not found.\n");
		return (-1);
	}
	if (access(name, X_OK) == -1)
	{
		WR(2, "42sh : ");
		ft_putstr_fd(name, 2);
		WR(2, ": %s : permission denied.\n");
		return (-1);
	}
	return (0);
}
