/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:15:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 18:18:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_execve(t_data *d)
{
	char		**split;

	split = ft_get_exe(d->tree->command, d->env);
	if (split != NULL)
		execve(split[0], split, d->env);
	return (-1);
}
