/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:51:18 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/03 23:53:04 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int print_x(char chr, t_fmtblk blk, va_list ap)
{
	char *tmp;
	uintmax_t value;

	tmp = NULL;
	value = va_arg(ap, uintmax_t);
	if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base((unsigned int) value, 16, 0);
	else if (blk.modifier == H)
		tmp = ft_uintmaxtoa_base((unsigned short) value, 16, 0);
	else if (blk.modifier == HH)
		tmp = ft_uintmaxtoa_base((unsigned char) value, 16, 0);
	else if (blk.modifier == L || chr == 'p')
		tmp = ft_uintmaxtoa_base((unsigned long) value, 16, 0);
	else if (blk.modifier == LL)
		tmp = ft_uintmaxtoa_base((unsigned long long) value, 16, 0);
	else if (blk.modifier == J)
		tmp = ft_uintmaxtoa_base(value, 16, 0);
	else if (blk.modifier == Z)
		tmp = ft_uintmaxtoa_base((size_t)value, 16, 0);
	return (chr == 'p'? pnf_p(blk, tmp, value) : pnf_x(blk, tmp, value));
}

int print_X(char chr, t_fmtblk blk, va_list ap)
{
	char *tmp;
	uintmax_t value;

	tmp = NULL;
	chr = 'X';
	value = va_arg(ap, uintmax_t);
	if (blk.modifier == 1)
		tmp = ft_uintmaxtoa_base((unsigned short)value, 16, 1);
	else if (blk.modifier == 2)
		tmp = ft_uintmaxtoa_base((unsigned char)value, 16, 1);
	else if (blk.modifier == 4)
		tmp = ft_uintmaxtoa_base((unsigned long)value, 16, 1);
	else if (blk.modifier == 8)
		tmp = ft_uintmaxtoa_base((ULL)value, 16, 1);
	else if (blk.modifier == 16)
		tmp = ft_uintmaxtoa_base(value, 16, 1);
	else if (blk.modifier == 32)
		tmp = ft_uintmaxtoa_base((size_t)value, 16, 1);
	else
		tmp = ft_uintmaxtoa_base((unsigned int)value, 16, 1);
	return (pnf_x(blk, tmp, value));
}
