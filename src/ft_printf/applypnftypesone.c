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

char	*pnf_d(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (flags & ZERO_P)
		padding = '0';
	if (flags & BLNK_P || flags == '\0' || preci)
		padding = ' ';
	tmp = con;
	if ((int)ft_strlen(con) < preci)
		tmp = addprecisiondioux(preci, con);
	ret = addblanknsign(ft_atoi(con), flags, tmp);
	if ((int)ft_strlen(con) < width)
	{
		tmp = addwidth(width, padding, flags, ret);
		ft_strdel(&ret);
		return (tmp);
	}
	return (ret);
}

char	*pnf_s(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (flags & ZERO_P)
		padding = '0';
	if (flags & BLNK_P || flags == '\0')
		padding = ' ';
	tmp = con;
	if ((int)ft_strlen(con) > preci)
		tmp = addprecisioncs(preci, con);
	else
		ret = tmp;
	if ((int)ft_strlen(con) < width)
		ret = addwidth(width, padding, flags, tmp);
	else
		ret = tmp;
	return (ret);
}

char	*pnf_u(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	ret = NULL;
	tmp = NULL;
	if (flags & ZERO_P)
		padding = '0';
	if (flags & BLNK_P || flags == '\0' || preci)
		padding = ' ';
	if ((int)ft_strlen(con) < preci)
		tmp = addprecisiondioux(preci, con);
	else
		ret = tmp;
	if ((int)ft_strlen(con) < width)
		tmp = addwidth(width, padding, flags, tmp);
	ret = tmp;
	return (ret);
}

char	*pnf_c(int width, unsigned char flags, char con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	padding = ' ';
	tmp = ft_strnew(1);
	ft_memset(tmp, con, 1);
	if ((int)ft_strlen(tmp) < width)
		ret = addwidth(width, padding, flags, tmp);
	else
		ret = tmp;
	return (ret);
}
