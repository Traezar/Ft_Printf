/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:27:34 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/03 23:29:20 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*print_d(char chr, t_fmtblk blk, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if (blk.modifier == 0 && chr == 'd')
		tmp = ft_itoa(va_arg(ap, int));
	else if (blk.modifier == 1 && chr == 'd')
		tmp = ft_itoa((short)va_arg(ap, int));
	else if (blk.modifier == 2 && chr == 'd')
		tmp = ft_itoa((char)va_arg(ap, int));
	else if ((blk.modifier == 4 && chr == 'd') || (chr == 'D'))
		tmp = ft_itoa((long)va_arg(ap, long));
	else if (blk.modifier == 8 && chr == 'd')
		tmp = ft_itoa((long long)va_arg(ap, long long));
	else if (blk.modifier == 16 && chr == 'd')
		tmp = ft_itoa(va_arg(ap, intmax_t));
	else if (blk.modifier == 32 && chr == 'd')
		tmp = ft_itoa(va_arg(ap, int));
	tmp = pnf_d(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}
