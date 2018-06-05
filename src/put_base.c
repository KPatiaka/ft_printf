/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:49:45 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/14 18:49:49 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rec(unsigned long long n, int base, char type, t_flags *flags)
{
	if (n >= (unsigned long long)base)
		rec(n / base, base, type, flags);
	if (n % base <= 9)
		n = n % base + 48;
	else
		n = (type == 'x') ? n % base + 48 + 39 : n % base + 48 + 7;
	flags->total += write(1, &n, 1);
}

void	put_base(unsigned long long n, char type, t_flags *flags)
{
	int base;

	if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'x' || type == 'X')
		base = 16;
	else if (type == 'b')
		base = 2;
	else
		base = 10;
	rec(n, base, type, flags);
}

int		base_len(unsigned long long num, char type)
{
	int len;
	int base;

	len = 1;
	if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'x' || type == 'X')
		base = 16;
	else if (type == 'b')
		base = 2;
	else
		base = 10;
	while (num /= base)
		len++;
	return (len);
}

void	flager_for_base(unsigned long long num, char type, t_flags *flags)
{
	int		len;

	len = base_len(num, type);
	flags->fullnum = flags->precision > len ? flags->precision : len;
	if (num == 0 && flags->precision == 0 && flags->dot == 1 \
		&& flags->sharp == 1 && (type == 'o' || type == 'O'))
		flags->dot++;
	flags->sharp = num == 0 ? 0 : flags->sharp;
	if (num == 0 && flags->precision == 0 && flags->dot == 1)
	{
		put_width_unsig(flags, (flags->fullnum - 1));
		return ;
	}
	if (flags->sharp == 1 && num != 0)
		flags->fullnum += (type == 'x' || type == 'X') ? 2 : 1;
	flager_for_base_two(num, type, flags, len);
	if ((flags->minus == 0) && (flags->width >= len || flags->precision >= len))
		flager_for_base_min(num, type, flags, len);
	else if ((flags->minus == 1) && (flags->width > len \
		|| flags->precision > len))
		flager_for_base_nomin(num, type, flags, len);
}

void	put_sharp(char type, t_flags *flags)
{
	if (type == 'x' || type == 'X')
		flags->total += (type == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	if (type == 'o' || type == 'O')
		flags->total += write(1, "0", 1);
}
