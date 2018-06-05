/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:05:59 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/10 20:14:09 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <stdio.h>
# define A(x) x == 's' || x == 'c' || x == 'u' || x == 'U' || x == 'd'
# define B(x) x == 'i' || x == 'D' || x == 'o' || x == 'O' || x == 'x'
# define C(x) x == 'X' || x == '%' || x == 'C' || x == 'S' || x == 'p'
# define D(x) x == 'b' || x == 'n'

typedef struct		s_flags
{
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
	int				total;
	int				mod;
	int				dot;
	int				binar;
	int				color;
	int				fullnum;
}					t_flags;

int					ft_printf(char *str, ...);
void				put_c(char c, t_flags *flags);
int					put_s(char *str, t_flags *flags);
void				put_n(long long n, t_flags *flags);
void				cleanflags(t_flags *flags);
void				put_base(unsigned long long n, char type, t_flags *flags);
void				rec(unsigned long long n, int base, \
					char type, t_flags *flags);
int					ft_atoi(char *str);
void				parse_flags(char **str, va_list *argp, t_flags *flags);
int					put_unic(wchar_t c);
int					put_unistr(wchar_t *unistr, t_flags *flags);
int					get_unicode_char_len(wchar_t c);
void				flager_for_s(char *s, t_flags *flags);
void				flager_c(char c, t_flags *flags);
void				flager_for_di(long long di, t_flags *flags);
int					num_len(long long num);
int					num_unsig_len(unsigned long long num);
void				mod_chek(char c, va_list *arg, t_flags *flags);
void				mod_chek_unsig(char c, va_list *arg, t_flags *flags);
void				unsignum(unsigned long long n, t_flags *flags);
void				put_width_unsig(t_flags *flags, int fullnum);
void				put_precision_unsig(t_flags *flags, int len);
void				flager_for_unsig(unsigned long long num, t_flags *flags);
void				put_width(t_flags *flags, int fullnum, int min);
void				put_precision(t_flags *flags, int len, int min);
void				flager_lc(wchar_t c, t_flags *flags);
void				flager_for_ls(wchar_t *unistr, t_flags *flags);
void				mod_chek_nomod(char c, va_list *argp, t_flags *flags);
void				flager_for_base(unsigned long long num, \
					char type, t_flags *flags);
void				put_sharp(char type, t_flags *flags);
void				flager_point(unsigned long long num, t_flags *flags);
int					base_len(unsigned long long num, char type);
void				print_di(long long di, t_flags *flags, int len, int min);
void				print_befor_pars(va_list *argp, t_flags *flags, char str);
void				print_after_pars(va_list *argp, t_flags *flags, char str);
void				mod_chek_base(char c, va_list *argp, t_flags *flags);
void				colors(va_list *argp, t_flags *flags, char *str);
void				flager_for_base_min(unsigned long long num, char type, \
					t_flags *flags, int len);
void				flager_for_base_nomin(unsigned long long num, char type, \
					t_flags *flags, int len);
void				flager_for_base_two(unsigned long long num, char type, \
					t_flags *flags, int len);
void				n_bonus(int *n, t_flags *flags);
void				print_befor_pars_two(va_list *argp, t_flags *flags, \
					char str);

#endif
