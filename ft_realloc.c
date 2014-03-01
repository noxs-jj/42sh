/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:40 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 16:55:21 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		printf("%s\n", "null ptr");
		return (ft_memalloc(size));
	}
	if (size == 0)
	{
		printf("%s\n", "size = 0");
		return (ptr);
	}
	printf("%s\n", "ft_realloc");
	new_ptr = ft_memalloc(size);
	if (new_ptr)
		printf("%s\n", "ft_realloc success");
	else
		printf("%s\n", "ft_realloc fail");
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
/*
char	**ft_realloc_tab(char **ptr, size_t size)
{
	char	**new_ptr;

	if (ptr == NULL)
	{
		printf("%s\n", "null ptr");
		return (ft_memalloc(size));
	}
	if (size == 0)
	{
		printf("%s\n", "size = 0");
		return (ptr);
	}
	printf("%s\n", "ft_realloc");
	new_ptr = ft_memalloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
*/
