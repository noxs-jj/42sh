/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:27:35 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/06 17:47:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef struct	s_dsplit
{
	size_t	i;
	size_t	y;
	size_t	nbr_s;
	size_t	s_len;
	char	**tab;
}				t_dsplit;

static int	count_word(char const *s, char c);
static int	strlen_word(char const *s, char c);

char		**ft_strsplit(char const *s, char c)
{
	t_dsplit	d;

	if (s == NULL)
		return (NULL);
	d.nbr_s = count_word(s, c);
	d.tab = (char **)malloc(sizeof(char *) * d.nbr_s + 1);
	d.i = 0;
	d.y = 0;
	while (s[d.i] != '\0')
	{
		while (s[d.i] == c && s[d.i] != '\0')
			d.i++;
		if (s[d.i] != c && s[d.i] != '\0')
		{
			d.tab[d.y] = ft_strsub(s, d.i, strlen_word(&s[d.i], c));
			d.y++;
		}
		while (s[d.i] != c && s[d.i] != '\0')
			d.i++;
	}
	d.tab[d.y] = '\0';
	return (d.tab);
}

static int	strlen_word(char const *s, char c)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		y++;
	}
	return (y);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			y++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (y);
}
