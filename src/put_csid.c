/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_csid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:56:34 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/14 12:56:36 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_c(char c, t_flags *flags)
{
	flags->total += write(1, &c, 1);
}

int		put_s(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i = (flags->precision > 0 && flags->precision < 7) \
		? flags->precision : 6;
		flags->total += write(1, "(null)", i);
		return (i);
	}
	while (str[i])
		i++;
	flags->total += write(1, str, i);
	return (i);
}

void	recursive_put_n(unsigned long long num, t_flags *flags)
{
	if (num > 9)
		recursive_put_n(num / 10, flags);
	num = num % 10 + 48;
	flags->total += write(1, &num, 1);
}

void	put_n(long long n, t_flags *flags)
{
	unsigned long long	num;

	if (n < 0)
		flags->total += write(1, "-", 1);
	num = (n < 0) ? -n : n;
	recursive_put_n(num, flags);
}

void	n_bonus(int *n, t_flags *flags)
{
	*n = flags->total;
}
