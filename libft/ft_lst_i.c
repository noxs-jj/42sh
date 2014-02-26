/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_i.c                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 12:32:41 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/01 17:32:00 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** content (int)
** Create new elem
*/

t_lst_i	*ft_lstnew_i(int content)
{
	t_lst_i	*tmp;

	tmp = (t_lst_i *)ft_memalloc(sizeof(t_lst_i));
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

/*
** content (int)
** Add elem to start of list
*/

void	ft_lstadd_i(t_lst_i **alst, t_lst_i *new)
{
	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	else if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

/*
** content (int)
** Add elem to end of list
*/

void	ft_lstaddend_i(t_lst_i **alst, t_lst_i *new)
{
	t_lst_i	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
