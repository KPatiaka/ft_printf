/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:29:34 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/10 20:37:12 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cleanflags(t_flags *flags)
{
	flags->sharp = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = -1;
	flags->precision = 0;
	flags->mod = 0;
	flags->dot = 0;
	flags->binar = 0;
}

int		ft_printf(char *str, ...)
{
	va_list		argp;
	t_flags		flags;

	flags.total = 0;
	va_start(argp, str);
	while (*str)
	{
		cleanflags(&flags);
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				return (0);
			if (*str == 's' || *str == 'c' || *str == 'u' || *str == 'U' \
				|| *str == 'd' || *str == 'i' || *str == 'D' || *str == 'o' \
				|| *str == 'O' || *str == 'x' || *str == 'X' || *str == '%' \
				|| *str == 'C' || *str == 'S' || *str == 'p' || *str == 'b' || *str == 'n')
				print_befor_pars(&argp, &flags, *str);
			else
			{
				parse_flags(&str, &argp, &flags);
				print_after_pars(&argp, &flags, *str);
			}
		}
		else
			flags.total += write(1, str, 1);
		str += (str) ? 1 : 0;
	}
	va_end(argp);
	return (flags.total);
}

void	print_befor_pars(va_list *argp, t_flags *flags, char str)
{
	if (str == 's')
		put_s(va_arg(*argp, char *), flags);
	else if (str == 'c')
		put_c((char)va_arg(*argp, int), flags);
	else if (str == 'u')
		unsignum(va_arg(*argp, unsigned int), flags);
	else if (str == 'U')
		unsignum(va_arg(*argp, unsigned long), flags);
	else if (str == 'd' || str == 'i')
		put_n(va_arg(*argp, int), flags);
	else if (str == 'D')
		put_n(va_arg(*argp, long), flags);
	else if (str == 'o' || str == 'O' || str == 'x' || str == 'X')
		put_base(va_arg(*argp, unsigned), str, flags);
	else if (str == '%')
		flags->total += write(1, "%", 1);
	else if (str == 'C')
		flags->total += put_unic(va_arg(*argp, wchar_t));
	else if (str == 'S')
		put_unistr(va_arg(*argp, wchar_t *), flags);
	else if (str == 'p')
		flager_point(va_arg(*argp, unsigned long long), flags);
	else if (str == 'b')
		put_base(va_arg(*argp, unsigned), str, flags);
	else if (str == 'n')
		put_n(flags->total, flags);
}

void	print_after_pars(va_list *argp, t_flags *flags, char str)
{
	if (flags->mod > 0)
		mod_chek(str, argp, flags);
	if (flags->mod == 0)
		mod_chek_nomod(str, argp, flags);
	if (str == 'u' || str == 'U')
		mod_chek_unsig(str, argp, flags);
	else if (str == '%')
		flager_c(str, flags);
}