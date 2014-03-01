/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 16:39:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

size_t	arraylen(char **array)
{
	size_t	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL && array[i][0] != '\0')
			++i;
	}
	else
		ft_putendl("Could not get length of NULL array");
	return (i);
}
