/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pos_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:56:24 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/05 15:04:58 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** return the cmp pos in str, else return 0
** TEST OK vjacquie
*/

int	lx_pos_op(char *str, char *cmp)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cmp[0])
			return (i - 1);
		i++;
	}
	return (0);
}
