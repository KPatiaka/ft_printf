/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:12:14 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/23 21:12:15 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_unsig_len(unsigned long long num)
{
	int len;

	len = 1;
	while (num /= 10)
		len++;
	return (len);
}

void	unsignum(unsigned long long n, t_flags *flags)
{
	if (n > 9)
		unsignum(n / 10, flags);
	n = n % 10 + 48;
	flags->total += write(1, &n, 1);
}

void	flager_for_unsig(unsigned long long num, t_flags *flags)
{
	int		len;
	int		fullnum;
	
	len = num_unsig_len(num);
	fullnum = flags->precision > len ? flags->precision : len;
	if ((flags->width == -1 && flags->precision == 0) || \
		(flags->width < len && flags->precision < len))
		unsignum(num, flags);
	if ((flags->minus == 0) && (flags->width > len || flags->precision > len))
	{
		put_width_unsig(flags, fullnum);
		put_precision_unsig(flags, len);
		unsignum(num, flags);
	}
	else if ((flags->minus == 1) && (flags->width > len || flags->precision > len))
	{
		put_precision_unsig(flags, len);
		unsignum(num, flags);
		put_width_unsig(flags, fullnum);
	}
}

void	put_width_unsig(t_flags *flags, int fullnum)
{
	int i;

	i = 0;
	while ((fullnum + i) < flags->width)
		{
			flags->total += (flags->zero == 1 && flags->minus == 0) \
			? write(1, "0", 1) : write(1, " ", 1);
			i++;
		}
}

void	put_precision_unsig(t_flags *flags, int len)
{
	int i;

	i = 0;
	while ((len + i) < flags->precision)
	{
		flags->total += (flags->precision > (len + i)) ? write(1, "0", 1) : 0;
		i++;
	}
}
