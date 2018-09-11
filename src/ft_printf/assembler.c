/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:11:43 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 15:02:49 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_fmtblk	formatblockmaker(char *str)
{
	t_fmtblk	store;

	store.flagstore = flaghandler(str);
	while (!(isflag(*str) == 1))
		str++;
	if (ft_isdigit(*str))
		store.width = ft_atoi(str);
	while (*str != '.' && (isconversionchr(*str) == 1) && (ismodi(*str) == 1))
		str++;
	if (*str == '.')
		str++;
	store.precision = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (isconversionchr(*str) == 1)
	{
		store.modifier = modihandler(&(*str));
		while (isconversionchr(*str) == 1)
			str++;
	}
	store.conver = *str;
	return (store);
}

int		ismodi(char c)
{
	char *s;

	s = "hljtzq\0";
	while (*s != '\0')
	{
		if (*s++ == c)
			return (c);
	}
	return (1);
}

char		*functiondispatcher(char chr, t_fmtblk head, va_list ap)
{
	char *(*f)(char chr, t_fmtblk head, va_list ap);

	if (((head.modifier == 4 && chr == 'c') || (chr == 'C')) ||
			((head.modifier == 4 && chr == 's') || (chr == 'S')))
		(f) = &print_wide;
	else if (chr == 'd' || chr == 'D')
		(f) = &print_d;
	else if (chr == 'o' || chr == 'O')
		(f) = &print_o;
	else if (chr == 'u' || chr == 'U')
		(f) = &print_u;
	else if (chr == 'x')
		(f) = &print_x;
	else if (chr == 'X')
		(f) = &print_X;
	else if (chr == 'c' || chr == 's')
		(f) = &print_cs;
	else if (chr == 'p')
		(f) = &print_x;
	if (chr == 'i')
		(f) = &print_d;
	if (chr == '%')
		return (print_per(head));
	return ((*f)(chr, head, ap));
}
