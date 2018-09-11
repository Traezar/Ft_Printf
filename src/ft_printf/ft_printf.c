/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:30:23 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 15:00:23 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

char	*outputstringmaker(char *strlst, va_list ap, char *strtbprnt)
{
	t_fmtblk	head;
	char		*unpackedconversion;
	char		*tmp;

	head = formatblockmaker(strlst);
	unpackedconversion = functiondispatcher(head.conver, head, ap);
	tmp = ft_strjoin(strtbprnt, unpackedconversion);
	ft_strdel(&strtbprnt);
	strtbprnt = tmp;
	return (strtbprnt);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char		*strtbprnt;
	int			len;

	strtbprnt = NULL;
	va_start(ap, format);
	strtbprnt = workhorse(ap, strtbprnt, format);
	va_end(ap);
	len = ft_strlen(strtbprnt);
	write(1, strtbprnt, len);
	ft_strdel(&strtbprnt);
	return (len);
}

char	*workhorse(va_list ap, char *strtbprnt, const char *format)
{
	char	*fmt;
	char	*tmp;
	int		i;

	i = 0;
	fmt = (char*)&format[i];
	strtbprnt = ft_strnew(0);
	while (fmt[i] != '\0')
	{
		fmt = &fmt[i];
		i = 0;
		while (fmt[i] != '%' && fmt[i] != '\0')
			i++;
		strtbprnt = ft_subnjoin(strtbprnt, fmt, 0, i);
		if (fmt[i] == '\0')
			break ;
		tmp = conversionblockunpacker(&fmt[++i]);
		i += (ft_strlen(tmp));
		strtbprnt = outputstringmaker(tmp, ap, strtbprnt);
		ft_strdel(&tmp);
	}
	return (strtbprnt);
}
