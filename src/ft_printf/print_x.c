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

char	*print_xp(char chr, t_fmtblk blk, va_list ap)
{
	char *tmp;

	tmp = NULL;
	if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base((int)va_arg(ap, uintmax_t), 16, 0);
	else if (chr == 'X')
		tmp = ft_uintmaxtoa_base((unsigned long)va_arg(ap, uintmax_t), 16, 1);
	else if (blk.modifier == 1)
		tmp = ft_uintmaxtoa_base((unsigned short)va_arg(ap, uintmax_t), 16, 0);
	else if (blk.modifier == 2)
		tmp = ft_uintmaxtoa_base((unsigned char)va_arg(ap, uintmax_t), 16, 0);
	else if (blk.modifier == 4 || chr == 'p')
		tmp = ft_uintmaxtoa_base((unsigned long)va_arg(ap, uintmax_t), 16, 0);
	else if (blk.modifier == 8)
		tmp = ft_uintmaxtoa_base((ULL)va_arg(ap, uintmax_t), 16, 0);
	else if (blk.modifier == 16)
		tmp = ft_uintmaxtoa_base(va_arg(ap, uintmax_t), 16, 0);
	else if (blk.modifier == 32)
		tmp = ft_uintmaxtoa_base((size_t)va_arg(ap, uintmax_t), 16, 0);
	tmp = pnf_xp(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}
