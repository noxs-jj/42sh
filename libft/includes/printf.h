/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:24:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:56:47 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *src, ...);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_print_c(va_list *ap, size_t *i, size_t *strlen_display);
void	ft_print_pcent(size_t *i, size_t *strlen_display);
void	ft_print_str(va_list *ap, size_t *i, size_t *strlen_display);
void	ft_print_nbr_int(va_list *ap, size_t *i, size_t *strlen_display);
void	ft_print_ptr(va_list *ap, size_t *i, size_t *strlen_display);
void	ft_print_no_param(const char (*tmp),
		size_t *i, size_t *strlen_display);
void	ft_putnbr(int n);

#endif
