/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:52:42 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/04 19:24:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*addprecisioncs(int precision, char *str)
{
	char *ret;

	if (precision < (int)ft_strlen(str))
	{
		ret = ft_strnew(precision);
		ft_strncpy(ret, str, precision);
	}
	else
	{
		ret = ft_strnew(ft_strlen(str));
		ft_strncpy(ret, str, precision);
	}
	return (ret);
}

char	*applysharp(char *str, char c)
{
	char	*tmp;

	if (c == 'o' || c == 'O')
	{
		if (str[0] == '0')
			return (ft_strdup(str));
		tmp = ft_strnew(ft_strlen(str));
		ft_memset(tmp, '0', ft_strlen(str));
		ft_strcpy((tmp + 1), str);
		str = tmp;
		str[0] = '0';
	}
	else if (c == 'x' || c == 'X')
	{
		tmp = ft_strnew(ft_strlen(str) + 2);
		ft_memset(tmp, '0', ft_strlen(str) + 2);
		ft_strcpy((tmp + 2), str);
		str = tmp;
		str[0] = '0';
		if (c == 'x')
			str[1] = 'x';
		else
			str[1] = 'X';
	}
	return (str);
}

char	*addwidth(int width, char pad, unsigned char flags, char *str)
{
	char	*tmp1;
	char	*tmp2;
	int		len;

	len = ft_strlen(str);
	if (width == 0 || width <= len)
		return (str);
	if (width > len)
	{
		width = width - len;
		tmp1 = ft_strnew(width);
		tmp1 = ft_memset(tmp1, pad, width);
		if (flags & RT_P)
			tmp2 = ft_strjoin(str, tmp1);
		else
			tmp2 = ft_strjoin(tmp1, str);
		str = ft_strdup(tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	return (str);
}

char	*addblanknsign(int value, unsigned char flags, char *str)
{
	char *ret;

	if ((flags & SIGNED) && (value >= 0))
	{
		ret = ft_strjoin("+", str);
		ft_strdel(&str);
	}
	else if ((flags & BLNK_P) && (value >= 0))
	{
		ret = ft_strjoin(" ", str);
		ft_strdel(&str);
	}
	ret = str;
	return (ret);
}

char	*addprecisiondioux(int precision, char *str)
{
	int		len;
	char	*tmp;
	char	*init;

	len = ft_strlen(str);
	if (precision > len)
		init = ft_strnew(precision);
	else
		return (str);
	if (str[0] == '-')
		len--;
	while (precision > len++)
	{
		tmp = ft_strjoin("0", str);
		str = ft_strcpy(init, tmp);
		free(tmp);
	}
	if (ft_strchr(str, '-') != NULL)
	{
		*ft_strchr(str, '-') = '0';
		str[0] = '-';
	}
	return (str);
}
