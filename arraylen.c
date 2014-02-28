/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 15:56:30 by nmohamed         ###   ########.fr       */
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
