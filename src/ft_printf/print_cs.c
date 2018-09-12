/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:29:50 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/03 23:35:40 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*print_cs(char chr, t_fmtblk blk, va_list ap)
{
	char	*tmp;
	tmp = NULL;
	if (chr == 'c')
	{
		chr = va_arg(ap, int);
		tmp = pnf_c(blk.width, blk.flagstore, chr);
		return (tmp);
	}
	else
		tmp = (va_arg(ap, char *));
	tmp = pnf_s(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}

char	*print_wide(char chr, t_fmtblk blk, va_list ap)
{
	wchar_t *wctmp;
	wchar_t *wstmp;

	wctmp = NULL;
	wstmp = NULL;
	if ((blk.modifier == 4 && chr == 'c') || chr == 'C')
	{
		*wctmp = va_arg(ap, wchar_t);
		return ((char *)wctmp);
	}
	else
	{
		wstmp = va_arg(ap, wchar_t*);
		return ((char *)wstmp);
	}
}

char	*print_u(char chr, t_fmtblk blk, va_list ap)
{
	char *tmp;

	tmp = NULL;
	if (blk.modifier == H && chr == 'u')
		tmp = ft_uintmaxtoa_base((unsigned short) va_arg(ap, size_t), 10, 1);
	else if (blk.modifier == HH && chr == 'u')
		tmp = ft_uintmaxtoa_base((unsigned char) va_arg(ap, uintmax_t), 10, 1);
	else if ((blk.modifier == L) || (chr == 'U'))
		tmp = ft_uintmaxtoa_base( va_arg(ap, unsigned long), 10, 1);
	else if (blk.modifier == LL)
		tmp = ft_uintmaxtoa_base((unsigned long long) va_arg(ap, uintmax_t), 10, 1);
	else if (blk.modifier == J)
		tmp = ft_uintmaxtoa_base( va_arg(ap, uintmax_t), 10, 1);
	else if (blk.modifier == Z)
		tmp = ft_uintmaxtoa_base((size_t) va_arg(ap, uintmax_t), 10, 1);
	else if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base( va_arg(ap,unsigned int), 10, 1);
	tmp = pnf_u(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}
