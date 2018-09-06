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
		ret = applysharp(tmp, 'o');
		free(tmp);
	}
	else
		ret = tmp;
	if ((int)ft_strlen(ret) < width)
	{
		tmp = addwidth(width, padding, flags, ret);
		free(ret);
		ret = tmp;
	}
	return (ret);
}

char	*pnf_xp(int width, unsigned char flags, int preci, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;

	tmp = addprecisiondioux(preci, con);
	if (flags & ZERO_P)
		padding = '0';
	else
		padding = ' ';
	if (flags & SH_ON)
	{
		ret = applysharp(tmp, 'x');
		free(tmp);
	}
	else
		ret = tmp;
	if ((int)ft_strlen(ret) < width)
	{
		tmp = addwidth(width, padding, flags, ret);
		free(ret);
		ret = tmp;
	}
	return (ret);
}
