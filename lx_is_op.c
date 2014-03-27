/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_is_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:56:24 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:05 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** search if '|', '>', '<' or ">>" are in the string
*/

int		lx_is_op(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		if (str[i] == '>' && str[i + 1] == '>')
			return (4);
		if (str[i] == '>')
			return (3);
		if (str[i] == '<')
			return (2);
		i++;
	}
	return (0);
}
