/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:40 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/27 15:41:56 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_memalloc(size));
	if (size == 0)
		return (ptr);
	new_ptr = ft_memalloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
