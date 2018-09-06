/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:31:15 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 13:43:27 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define SH_ON  1
# define SIGNED 2
# define BLNK_P 4
# define RT_P   8
# define ZERO_P 16
# define H  1
# define HH 2
# define L  4
# define LL 8
# define J  16
# define Z  32
# define ULL unsigned long long

typedef struct	s_fmt
{
	int				width;
	int				precision;
	char			conver;
	unsigned char	flagstore;
	unsigned char	modifier;
}				t_fmtblk;

int				ft_printf(const char *format, ...);
char			*workhorse(va_list ap, char *strtbprnt, const char	*format);
char			*conversionblockunpacker(const char *format);
int				isconversionchr(char c);
char			flaghandler(char *str);
t_fmtblk		formatblockmaker(char *str);
int				modihandler(char *str);
char			*outputstringmaker(char *strlst, va_list ap, char *strtbprnt);
char			*functiondispatcher (char chr, t_fmtblk head, va_list ap);
char			*print_d(char chr, t_fmtblk blk, va_list ap);
char			*print_cs(char chr, t_fmtblk blk, va_list ap);
char			*print_u(char chr, t_fmtblk blk, va_list ap);
char			*print_o(char chr, t_fmtblk blk, va_list ap);
char			*print_xp(char chr, t_fmtblk blk, va_list ap);
char			*print_wide(char chr, t_fmtblk blk, va_list ap);
char			*addprecisioncs(int precision, char *str);
char			*addprecisiondioux(int precision, char *str);
char			*applysharp(char *str, char c);
char			*addwidth(int width, char pad, unsigned char flags, char *str);
char			*addblanknsign(int value, unsigned char flags, char *str);
char			*pnf_d(int width, unsigned char flags, int preci, char *con);
char			*pnf_s(int width, unsigned char flags, int preci, char *con);
char			*pnf_u(int width, unsigned char flags, int preci, char *con);
char			*pnf_c(int width, unsigned char flags, char con);
char			*pnf_o(int width, unsigned char flags, int preci, char *con);
char			*pnf_xp(int width, unsigned char flags, int preci, char *con);
#endif
