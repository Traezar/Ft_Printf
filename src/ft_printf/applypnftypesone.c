/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applypnftypesone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:01:43 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 15:01:46 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"



int pnf_s(t_fmtblk blk, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int  value;

	if (con == NULL)
	{
		write(1,"(null)", 6);
		return(6);
	}
	if (blk.flagstore & ZERO_P)
		padding = '0';
	if (blk.flagstore & BLNK_P || blk.flagstore == '\0')
		padding = ' ';
		tmp = con;
		tmp = addprecisioncs(blk.precision, con);
		ret = addwidthcs(blk.width, blk.flagstore, tmp);
		value = ft_strlen(ret);
		write(1,ret, value);
		ft_strdel(&ret);
		return (value);
}

int pnf_u(t_fmtblk blk, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int 	value;

	ret = NULL;
	tmp = NULL;
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';;
	tmp = addprecisiondioux(blk.precision, con);
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1,ret, value);
	ft_strdel(&ret);
	return (value);
}

int pnf_c(t_fmtblk blk, char con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int  value;

	value = 0;
	if (con == 0 )
	{
		padding = ' ';
		write(1, &padding, blk.width == 0? 0:blk.width - 1);
		write(1, &value, 1);
		return (blk.width == 0? 1:blk.width);
	}
	padding = ' ';
	tmp = ft_strnew(1);
	ft_memset(tmp, con, 1);
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1,ret, value);
	ft_strdel(&ret);
	return (value);
}
