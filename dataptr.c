/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:42:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/21 12:45:56 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if need data everywhere cal this to get ptr of data struct
** TEST OK jmoiroux
*/

t_data	*dataptr(t_data *d)
{
	static t_data	*save = NULL;

	if (save == NULL)
		save = d;
	else
		return (save);
	return (save);
}
