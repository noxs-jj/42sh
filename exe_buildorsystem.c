/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_buildorsystem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:38:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/14 16:08:07 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** check md to exec, lubch it by build or execve in fork()
** TEST jmoiroux
*/

int		exe_build_system(t_data *d)
{
	if (build_check(d) == 1)
		return (1);
	return (exe_execve(d));
}
