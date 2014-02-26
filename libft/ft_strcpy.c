/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:54:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2013/12/07 16:32:44 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = ((char *)s2)[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
