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

int  pnf_o(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int 	retn;

	if (value == 0  && blk.dot)
			con = "";
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(blk.precision, con);
	if (blk.flagstore & SH_ON)
		ret = applysharp(tmp, blk.flagstore & O_X ? 'O':'o');
	else
	{
		ret = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	tmp = addwidth(blk.width, padding, blk.flagstore, ret);
	retn = ft_strlen(tmp);
	write(1,tmp, retn);
	ft_strdel(&tmp);
	return (retn);

}

int pnf_x(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int 	retn;

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
	{
		ret = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	tmp = addwidth(blk.width, padding,blk.flagstore, ret);
	if ((blk.flagstore & SH_ON) && ft_strchr(tmp,'x') != (tmp + 1)
	 	&& (blk.flagstore & ZERO_P))
	{
		*ft_strchr(tmp,'x') = '0';
		*(tmp + 1) = 'x';
	}
	retn = ft_strlen(tmp);
	write(1,tmp, retn);
	ft_strdel(&tmp);
	return (retn);
}

int				pnf_wc(wchar_t con)
{
		write(1, &con, 1);
		return (1);
}

int				pnf_ws(wchar_t *con)
{
	int writelen;

	if (con == NULL)
		return (0);
	writelen = 0;
	while(*con != '\0')
		writelen += pnf_wc(*con++);
	return(writelen);

}

int pnf_p(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		retn;

	if (value == 0  && blk.dot)
			con = "";
	tmp = addprecisiondioux(blk.precision, con);
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	ret = applysharp(tmp, 'x');
	tmp = addwidth(blk.width, padding,blk.flagstore, ret);
	if ((blk.flagstore & SH_ON) && ft_strchr(tmp,'x') != (tmp + 1)
	 	&& (blk.flagstore & ZERO_P))
	{
		*ft_strchr(tmp,'x') = '0';
		*(tmp + 1) = 'x';
	}
	retn = ft_strlen(tmp);
	write(1,tmp, retn);
	ft_strdel(&tmp);
	return (retn);
}
