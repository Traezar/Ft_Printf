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

	if (precision)
	{
		ret = ft_strnew(precision);
		ft_strncpy(ret, str, precision);
	}
	else
	{
		ret = ft_strnew(ft_strlen(str));
		ft_strncpy(ret, str, ft_strlen(str));
	}
	return (ret);
}

char	*addwidthcs(int width, unsigned char flags, char *str)
{
	char	*tmp1;
	char	*tmp2;
	int		len;

	len = ft_strlen(str);
	if (width <= 0 || width <= len)
	{
		tmp1 = ft_strdup(str);
		ft_strdel(&str);
		return (tmp1);
	}
	width = width - len;
	tmp1 = ft_strnew(width);
	tmp1 = ft_memset(tmp1, ' ', width);
	if (flags & RT_P)
		tmp2 = ft_strjoin(str, tmp1);
	else
		tmp2 = ft_strjoin(tmp1, str);
	ft_strdel(&str);
	str = ft_strdup(tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (str);
}

char	*applysharp(char *str, char c)
{
	char	*tmp;
	char 	*ret;

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
	ret = ft_strdup(str);
	ft_strdel(&str);
	return (ret);
}



char	*addspace(int value, unsigned char flags, char *str)
{
	char *init;

	init = ft_strnew(ft_strlen(str) + 1);
	if ((flags & BLNK_P) && (value >= 0) && str[0] != ' ' )
	{
		ft_memset(init,' ',1);
		ft_strcpy(init + 1, str);
	}
	else
		ft_strcpy(init,str);
	ft_strdel(&str);
	return (init);
}

char	*addsign(int value, unsigned char flags, char *str)
{
	char *init;
	init = ft_strnew(ft_strlen(str) + 1);
	if ((flags & SIGNED) && (value >= 0))
	{
		ft_memset(init,'+',1);
		ft_strcpy(init + 1, str);
	}
	else
		ft_strcpy(init, str);
	ft_strdel(&str);
	return(init);
}

char *checkneg(int value, char pad, int preci, char *str)
{
	char *ret;

	preci = 0;
	if (ft_strchr(str, ' ') == NULL)
		pad = '0';
	if ((value < 0)  && pad == '0')
	{
		if (ft_strchr(str, '-') != NULL)
		{
			*ft_strchr(str, '-') = pad;
			str[0] = '-';
		}
	}
	else if ((value >= 0)  && pad == '0')
	{
		if (ft_strchr(str, '+') != NULL)
		{
			*ft_strchr(str, '+') = pad;
			str[0] = '+';
		}
	}
	ret = ft_strdup(str);
	ft_strdel(&str);
	return(ret);
}
