/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flager_for_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:03:49 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/22 19:03:50 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(long long num)
{
	int len;

	len = 1;
	while (num /= 10)
		len++;
	return (len);
}

void	flager_for_di(long long di, t_flags *flags)
{
	int		len;
	int		fullnum;
	int		min;

	len = num_len(di);
	fullnum = flags->precision > len ? flags->precision : len;
	if (di == 0 && flags->precision == 0 && flags->dot == 1)
	{
		put_width_unsig(flags, (fullnum - 1));
		return ;
	}
	if ((flags->width == -1 && flags->precision == 0) || \
		(flags->width < len && flags->precision < len))
	{
		if (flags->plus == 1 && di >= 0)
			flags->total += write(1, "+", 1);
		if (flags->space == 1 && di > 0 && flags->plus != 1)
			flags->total += write(1, " ", 1);
		put_n(di, flags);
	}
	min = di < 0 ? 1 : 0;
	di = di < 0 ? di * -1 : di;
	flags->zero = flags->minus == 1 ? 0 : flags->zero;
	print_di(di, flags, len, min);
}

void	print_di(long long di, t_flags *flags, int len, int min)
{
	int		fullnum;

	fullnum = flags->precision > len ? flags->precision : len;
	if ((flags->minus == 0) && \
		(flags->width >= fullnum || flags->precision > len))
	{
		flags->zero = (flags->precision >= len) ? 0 : flags->zero;
		put_width(flags, fullnum, min);
		put_precision(flags, len, min);
		put_n(di, flags);
	}
	else if ((flags->minus == 1) && \
		(flags->width >= fullnum || flags->precision > len))
	{
		put_precision(flags, len, min);
		put_n(di, flags);
		put_width(flags, fullnum, min);
	}
}

void	put_width(t_flags *flags, int fullnum, int min)
{
	int i;

	i = (flags->plus == 1 && min != 1) ? 1 : 0;
	i = (flags->space == 1 && flags->plus != 1 && min != 1 && \
		flags->width > flags->precision) ? (i + write(1, " ", 1) \
		+ (++flags->total - flags->total)) : i;
	i += (flags->width > flags->precision && flags->zero != 1 \
		&& flags->space == 1 && flags->plus != 1 && min != 1) ? 1 : 0;
	i += (flags->minus == 1 && flags->space == 1 \
		&& flags->plus != 1 && min != 1) ? 1 : 0;
	flags->total += (flags->plus == 1 && min != 1 \
		&& flags->zero == 1) ? write(1, "+", 1) : 0;
	flags->total += (min == 1 && flags->zero == 1) ? write(1, "-", 1) : 0;
	while ((fullnum + i + min) < flags->width)
	{
		flags->total += (flags->zero == 1 && flags->minus == 0) \
		? write(1, "0", 1) : write(1, " ", 1);
		i++;
	}
}

void	put_precision(t_flags *flags, int len, int min)
{
	int i;

	i = 0;
	flags->total += (flags->space == 1 && flags->plus != 1 \
		&& min != 1) ? write(1, " ", 1) : 0;
	flags->total += (flags->plus == 1 && min != 1 && \
		flags->zero != 1) ? write(1, "+", 1) : 0;
	flags->total += (min == 1 && flags->zero != 1) ? write(1, "-", 1) : 0;
	while ((len + i) < flags->precision)
	{
		flags->total += (flags->precision > (len + i)) ? write(1, "0", 1) : 0;
		i++;
	}
}
