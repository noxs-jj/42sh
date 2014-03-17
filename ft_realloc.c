/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:40 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/17 13:18:28 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		ft_printf("%s\n", "null ptr");
		return (ft_memalloc(size));
	}
	if (size == 0)
	{
		ft_printf("%s\n", "size = 0");
		return (ptr);
	}
	new_ptr = ft_memalloc(size);
	if (!(new_ptr))
	{
		WR(2, "Malloc error (ft_realloc)");
		return (NULL);
	}
	return (ft_memcpy(new_ptr, ptr, size));
}
