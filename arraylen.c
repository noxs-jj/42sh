/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/19 13:23:43 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

size_t	arraylen(char **array)
{
	size_t	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
			++i;
	}
	else
		ft_putendl("Could not get length of NULL array");
	return (i);
}
