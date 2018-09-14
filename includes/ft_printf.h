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
# define O_X 		32

# define H  1
# define HH 2
# define L  4
# define LL 8
# define J  16
# define Z  32
# define ULL unsigned long long

typedef struct	s_fmt
{
	int				dot;
	int				width;
	int				precision;
	char			conver;
	char 			star;
	unsigned char	flagstore;
	unsigned char	modifier;
}				t_fmtblk;

int				ft_printf(const char *format, ...);
int 			workhorse(va_list ap, const char	*format);
char			*conversionblockunpacker(const char *format);
int				ismodi(char c);
char			isflag(char c);
int				isconversionchr(char c);
char			flaghandler(char *str);
t_fmtblk	formatinit(t_fmtblk	*store);
t_fmtblk		formatblockmaker(char *str);
int				modihandler(char *str);
int       outputstringmaker(char *strlst, va_list ap);
int       functiondispatcher (char chr, t_fmtblk head, va_list ap);
int       print_d(char chr, t_fmtblk blk, va_list ap);
int       print_cs(char chr, t_fmtblk blk, va_list ap);
int       print_u(char chr, t_fmtblk blk, va_list ap);
int       print_o(char chr, t_fmtblk blk, va_list ap);
int       print_x(char chr, t_fmtblk blk, va_list ap);
int       print_X(char chr,t_fmtblk blk, va_list ap) ;
int       print_i(char chr, t_fmtblk blk, va_list ap);
int       print_per( t_fmtblk blk);
int       print_wide(char chr, t_fmtblk blk, va_list ap);
char			*addprecisioncs(int precision, char *str);
char			*addprecisiondioux(int precision, char *str);
char			*applysharp(char *str, char c);
char			*addwidth(int width, char pad, unsigned char flags, char *str);
char			*addwidthcs(int width, unsigned char flags, char *str);
char			*addspace(int value, unsigned char flags, char *str);
char			*addsign(int value, unsigned char flags, char *str);
char 			*checkneg(int value, char pad, int preci, char *str);
int       pnf_d(t_fmtblk blk, char *con, intmax_t value);
int       pnf_s(t_fmtblk blk, char *con);
int       pnf_u(t_fmtblk blk, char *con);
int       pnf_c(t_fmtblk blk, char con);
int       pnf_o(t_fmtblk blk, char *con, uintmax_t value);
int       pnf_x(t_fmtblk blk, char *con,uintmax_t value);
int 			pnf_p(t_fmtblk blk, char *con, uintmax_t value);
int				pnf_wc(wchar_t tmp);
int				pnf_ws(wchar_t *tmp);
#endif
