/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 12:27:13 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/15 12:33:31 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_sigpipe(int i)
{
	ft_putstr("SIGPIPE\n");
	(void)i;
	ft_putstr(PROMPT);
}
