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

	if (ft_atoi(con) == 0)
			con = "";
	if (flags & ZERO_P)
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(preci, con);
	if (flags & SH_ON)
		ret = applysharp(tmp, flags & O_X ? 'O':'o');
	else
		ret = tmp;
	tmp = addwidth(width, padding, flags, ret);
	return (tmp);
}

char	*pnf_x(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (value == 0  && blk.dot)
			con = "";
	tmp = addprecisiondioux(blk.precision, con);
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	if (blk.flagstore  & SH_ON  && value != 0)
		ret = applysharp(tmp, blk.flagstore & O_X ? 'X':'x');
	else
		ret = tmp;
	tmp = addwidth(blk.width, padding,blk.flagstore, ret);
	if ((blk.flagstore & SH_ON) && ft_strchr(tmp,'x') != (tmp + 1)
	 	&& (blk.flagstore & ZERO_P))
	{
		*ft_strchr(tmp,'x') = '0';
		*(tmp + 1) = 'x';
	}
	return (tmp);
}
