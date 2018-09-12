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
		tmp = ft_itoa(va_arg(ap, intmax_t));
	else if (blk.modifier == 1 && chr == 'd')
		tmp = ft_itoa((short) va_arg(ap, int));
	else if (blk.modifier == 2 && chr == 'd')
		tmp = ft_itoa((char)va_arg(ap, intmax_t));
	else if ((blk.modifier == 4 && chr == 'd') || (chr == 'D'))
		tmp = ft_intmaxtoa_base((long) va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 8 && chr == 'd')
		tmp = ft_intmaxtoa_base((long long) va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 16 && chr == 'd')
		tmp = ft_intmaxtoa_base(va_arg(ap, intmax_t), 10, 0);
	else if (blk.modifier == 32 && chr == 'd')
		tmp = ft_intmaxtoa_base((size_t)va_arg(ap, intmax_t), 10, 0);
	tmp = pnf_d(blk.width, blk.flagstore, blk.precision, tmp);
	return (tmp);
}

char	*pnf_d(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int 	value;

	value = ft_atoi(con);
	if ( !ft_strcmp(con,"0")  && !(flags) && !preci)
			con = "\0";
	if (flags & ZERO_P || preci > width)
		padding = '0';
	else
		padding = ' ';
	ret = addprecisiondioux(preci, con);
	tmp = addsign(value, flags, ret);
	if (width > preci && preci && width)
		padding = ' ';
	ret = addwidth(width, padding, flags, tmp);
	tmp = addspace(value, flags, ret);
	ret = checkneg(value, padding, preci, tmp);
	return (ret);
}

char	*addprecisiondioux(int precision, char *str)
{
	int		len;
	char	*init;

	len = ft_strlen(str);
	if (str[0] == '-')
			len--;
	if (precision <= 0 || precision <= len)
			return (str);
		init = ft_strnew(precision + len);
	precision = precision - len;
	ft_memset(init, '0', precision);
	ft_strcpy(init + precision, str);
	return (init);
}

char	*addwidth(int width, char pad, unsigned char flags, char *str)
{
	char	*tmp1;
	char	*tmp2;
	int		len;

	len = ft_strlen(str);
	if (width <= 0 || width <= len)
		return (str);
	width = width - len;
	tmp1 = ft_strnew(width + 1);
	tmp1 = ft_memset(tmp1, pad, width);
	if (flags & RT_P)
		tmp2 = ft_strjoin(str, tmp1);
	else
		tmp2 = ft_strjoin(tmp1, str);
	str = ft_strdup(tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (str);
}
