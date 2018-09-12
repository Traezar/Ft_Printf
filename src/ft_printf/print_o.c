/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:36:03 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/03 23:57:01 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*print_o(char chr, t_fmtblk blk, va_list ap)
{
	char *tmp;

	tmp = NULL;
	if (blk.modifier == 1&& !(chr == 'O'))
		tmp = ft_uintmaxtoa_base((unsigned short) va_arg(ap, uintmax_t), 8, 0);
	else if (blk.modifier == 2)
		tmp = ft_uintmaxtoa_base((unsigned char) va_arg(ap, uintmax_t), 8, 0);
	else if ((blk.modifier == 4) || chr == 'O')
		tmp = ft_uintmaxtoa_base((unsigned long) va_arg(ap, uintmax_t), 8, 1);
	else if (blk.modifier == 8)
		tmp = ft_uintmaxtoa_base((ULL) va_arg(ap, uintmax_t), 8, 0);
	else if (blk.modifier == 16)
		tmp = ft_uintmaxtoa_base( va_arg(ap, uintmax_t), 8, 0);
	else if (blk.modifier == 32)
		tmp = ft_uintmaxtoa_base((size_t) va_arg(ap, uintmax_t), 8, 0);
	else if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base((unsigned int) va_arg(ap, uintmax_t), 8, 0);
	tmp = pnf_o(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}

char	*print_per( t_fmtblk blk)
{
	char	padding;
	char	*tmp;
	char	*ret;

	ret = ft_strnew(1);
	ft_memset(ret, '%', 1);
	if (blk.flagstore & ZERO_P)
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(blk.precision, ret);
	tmp = addwidth(blk.width, padding, blk.flagstore, ret);
	ret = tmp;
	return (ret);
}

char	*print_i(char chr, t_fmtblk blk, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if (blk.modifier == 0 && chr == 'i')
		tmp = ft_itoa(va_arg(ap, intmax_t));
	else if (blk.modifier == 1 && chr == 'i')
		tmp = ft_itoa((short) va_arg(ap, int));
	else if (blk.modifier == 2 && chr == 'i')
		tmp = ft_itoa((char)va_arg(ap, intmax_t));
	else if ((blk.modifier == 4 && chr == 'i'))
		tmp = ft_intmaxtoa_base((long) va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 8 && chr == 'i')
		tmp = ft_intmaxtoa_base((long long) va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 16 && chr == 'i')
		tmp = ft_intmaxtoa_base(va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 32 && chr == 'i')
		tmp = ft_intmaxtoa_base((size_t)va_arg(ap, intmax_t), 10, 0);
	tmp = pnf_d(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}
