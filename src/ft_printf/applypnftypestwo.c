/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applypnftypestwo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:59:06 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 14:59:09 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*pnf_o(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (flags & ZERO_P)
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(preci, con);
	if (flags & SH_ON)
	{
		ret = applysharp(tmp, flags & O_X ? 'O':'o');
	}
	else
		ret = tmp;
	if ((int)ft_strlen(ret) < width)
	{
		tmp = addwidth(width, padding, flags, ret);
		ret = tmp;
	}
	return (ret);
}

char	*pnf_x(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (value == 0)
			con = "0\0";
	tmp = addprecisiondioux(blk.precision, con);
	if (blk.flagstore & ZERO_P || blk.precision > blk.width)
		padding = '0';
	else
		padding = ' ';
	if (blk.flagstore  & SH_ON  && value != 0)
		ret = applysharp(tmp, blk.flagstore & O_X ? 'X':'x');
	else
		ret = tmp;
	tmp = addwidth(blk.width, padding,blk.flagstore, ret);
	ret = tmp;
	return (ret);
}
