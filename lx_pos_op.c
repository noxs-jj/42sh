/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pos_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:56:24 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:17 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** return the cmp pos in str, else return 0
*/

int	lx_pos_op(char *str, char *cmp)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cmp[0])
			return (i);
		i++;
	}
	return (0);
}
