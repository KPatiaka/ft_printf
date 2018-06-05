/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flager_for_base_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 21:12:55 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/06/04 21:12:59 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flager_for_base_min(unsigned long long num, char type, \
	t_flags *flags, int len)
{
	if (flags->zero == 1 && flags->sharp == 1 && flags->precision < len)
		put_sharp(type, flags);
	(flags->sharp == 1 && flags->precision > len && \
		(type == 'o' || type == 'O')) ? flags->fullnum-- : 0;
	put_width_unsig(flags, flags->fullnum);
	if (flags->sharp == 1 && flags->precision > len)
		(type == 'o' || type == 'O') ? 0 : put_sharp(type, flags);
	put_precision_unsig(flags, len);
	if (flags->zero == 0 && flags->sharp == 1 && flags->precision < len)
		put_sharp(type, flags);
	put_base(num, type, flags);
}

void	flager_for_base_nomin(unsigned long long num, char type, \
	t_flags *flags, int len)
{
	if (flags->sharp == 1 && flags->precision > len)
		(type == 'o' || type == 'O') ? \
	flags->fullnum-- : put_sharp(type, flags);
	put_precision_unsig(flags, len);
	if (flags->sharp == 1 && flags->precision < len)
		put_sharp(type, flags);
	put_base(num, type, flags);
	put_width_unsig(flags, flags->fullnum);
}

void	flager_for_base_two(unsigned long long num, char type, \
	t_flags *flags, int len)
{
	if ((flags->width == -1 && flags->precision == 0) || (flags->width < len \
		&& flags->precision < len))
	{
		if (flags->sharp == 1 && num != 0)
			put_sharp(type, flags);
		put_base(num, type, flags);
	}
	flags->zero = ((flags->sharp == 1) && \
		flags->precision > len) ? 0 : flags->zero;
}
