/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:38:57 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/06/04 19:38:59 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	colors(va_list *argp, t_flags *flags, char *str)
{
	if (flags->color == 1)
		write(1, "\033[01;34m", 8);
	if (flags->color == 2)
		write(1, "\033[01;33m", 8);
	if (flags->color == 3)
		write(1, "\033[01;32m", 8);
	if (flags->color == 4)
		write(1, "\033[01;31m", 8);
	if (flags->color == 5)
		write(1, "\033[01;35m", 8);
	print_after_pars(argp, flags, *str);
}
