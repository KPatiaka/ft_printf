/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:01:11 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/16 17:01:15 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *str)
{
	int	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		str += 1;
	}
	return (res);
}

void	parse_flags(char **str, va_list *argp, t_flags *flags)
{
	char	*temp = NULL;

	temp = *str;
	while (**str && (**str != 'd' && **str != 'i' && **str != 's' && **str != 'S' \
		&& **str != 'p' && **str != 'D' && **str != 'o' && **str != 'O' \
		&& **str != 'u' && **str != 'U' && **str != 'x' && **str != 'X' \
		&& **str != 'c' && **str != 'C' && **str != '%'))
	{
		if (**str == '0')
			flags->zero = 1;
		if (**str == '-')
			flags->minus = 1;
		if (**str == '+')
			flags->plus = 1;
		if (**str == '#')
			flags->sharp = 1;
		if (**str == ' ')
			flags->space = 1;
		if (**str == 'b')
			flags->binar = 1;
		if (**str == '*')
			flags->width = va_arg(*argp, int);
		if (**str >= '0' && **str <= '9')
		{
			flags->width = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				*str += 1;
			*str -= 1;
		}
		if (**str == '.')
		{
			*str += 1;
			flags->dot = 1;
			flags->precision = (**str == '*') ? va_arg(*argp, int) : ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				*str += 1;
			*str -=  (**str == '*') ? 0: 1;
		}
		if (**str == 'h' && *(*str + 1) == 'h')
			flags->mod = (flags->mod > 1) ? flags->mod : 1;
		if (**str == 'h' && *(*str + 1) != 'h' && *(*str - 1) != 'h')
			flags->mod = (flags->mod > 2) ? flags->mod : 2;;
		if (**str == 'l' && *(*str + 1) != 'l' && *(*str - 1) != 'l')
			flags->mod = (flags->mod > 3) ? flags->mod : 3;;
		if (**str == 'l' && *(*str + 1) == 'l')
			flags->mod = (flags->mod > 4) ? flags->mod : 4;;
		if (**str == 'j')
			flags->mod = (flags->mod > 5) ? flags->mod : 5;;
		if (**str == 'z')
			flags->mod = (flags->mod > 6) ? flags->mod : 6;;
		*str += (**str) ? 1 : 0;
	}
	if (**str != 'd' && **str != 'i' && **str != 's' && **str != 'S' \
		&& **str != 'p' && **str != 'D' && **str != 'o' && **str != 'O' \
		&& **str != 'u' && **str != 'U' && **str != 'x' && **str != 'X' \
		&& **str != 'c' && **str != 'C' && **str != '%')
		*str = temp;
}
