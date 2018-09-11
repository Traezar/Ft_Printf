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
		tmp = addprecisioncs(preci, con);
		ret = addwidthcs(width, flags, tmp);
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
	tmp = addprecisiondioux(preci, con);
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
	ret = addwidth(width, padding, flags, tmp);
	return (ret);
}
