/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flager_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:40:53 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/29 19:40:56 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flager_point(unsigned long long num, t_flags *flags)
{
	int		len;

	len = (base_len(num, 'x')) + 2;
	if (flags->minus == 0)
	{
		if (flags->zero == 1 && flags->width > len)
			put_sharp('x', flags);
		put_width_unsig(flags, len);
		if (flags->zero != 1)
			put_sharp('x', flags);
		put_base(num, 'x', flags);
	}
	if (flags->minus == 1)
	{
		put_sharp('x', flags);
		put_base(num, 'x', flags);
		put_width_unsig(flags, len);
	}
}
