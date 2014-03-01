/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:27:35 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/01 11:51:51 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_strcountw(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			words++;
			s = ft_strchr(s, c);
		}
		else
			s++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		words;
	char const	*p;
	size_t		i;

	words = ft_strcountw(s, c);
	if (!(split = (char **)ft_memalloc(sizeof(*split) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		p = ft_strchr(s, c);
		split[i] = ft_strsub(s, 0, p ? (size_t)(p - s) : ft_strlen(s));
		if (!split[i])
			break ;
		s = p;
		i++;
	}
	split[i] = '\0';
	return (split);
}
