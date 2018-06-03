/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_my_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:05:48 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/23 19:05:50 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_chek(char c, va_list *argp, t_flags *flags)
{
	if (((c == 'c') && flags->mod == 3) || c == 'C')
		flager_lc(va_arg(*argp, wchar_t), flags);
	else if (((c == 's') && flags->mod == 3) || c == 'S')
		flager_for_ls(va_arg(*argp, wchar_t *), flags);
	else if ((c == 'd' || c == 'i') && flags->mod == 1)
		flager_for_di((char)va_arg(*argp, int), flags);
	else if ((c == 'd' || c == 'i') && flags->mod == 2)
		flager_for_di((short)va_arg(*argp, int), flags);
	else if (c == 'D' || ((c == 'i' || c == 'd') && flags->mod == 3))
		flager_for_di(va_arg(*argp, long), flags);
	else if ((c == 'd' || c == 'i') && flags->mod == 4)
		flager_for_di(va_arg(*argp, long long), flags);
	else if ((c == 'd' || c == 'i') && flags->mod == 5)
		flager_for_di(va_arg(*argp, intmax_t), flags);
	else if ((c == 'd' || c == 'i') && flags->mod == 6)
		flager_for_di(va_arg(*argp, size_t), flags);
	else if ((c == 'o' || c == 'O' || c == 'x' || c == 'X') && (flags->mod == 2 || flags->mod == 1))
		flager_for_base(va_arg(*argp, unsigned), c, flags);
	else if ((c == 'o' || c == 'O' || c == 'x' || c == 'X') && flags->mod == 3)
		flager_for_base(va_arg(*argp, unsigned long), c, flags);
	else if ((c == 'o' || c == 'O' || c == 'x' || c == 'X') && flags->mod == 4)
		flager_for_base(va_arg(*argp, unsigned long long), c, flags);
	else if ((c == 'o' || c == 'O' || c == 'x' || c == 'X') && flags->mod == 5)
		flager_for_base(va_arg(*argp, intmax_t), c, flags);
	else if ((c == 'o' || c == 'O' || c == 'x' || c == 'X') && flags->mod == 6)
		flager_for_base(va_arg(*argp, size_t), c, flags);
	else if ((c == 'b') && (flags->mod == 2 || flags->mod == 1))
		flager_for_base(va_arg(*argp, unsigned), c, flags);
	else if ((c == 'b') && flags->mod == 3)
		flager_for_base(va_arg(*argp, unsigned long), c, flags);
	else if ((c == 'b') && flags->mod == 4)
		flager_for_base(va_arg(*argp, unsigned long long), c, flags);
	else if ((c == 'b') && flags->mod == 5)
		flager_for_base(va_arg(*argp, intmax_t), c, flags);
	else if ((c == 'b') && flags->mod == 6)
		flager_for_base(va_arg(*argp, size_t), c, flags);
}

void	mod_chek_nomod(char c, va_list *argp, t_flags *flags)
{
	if ((c == 'd' || c == 'i') && flags->binar != 1)
		flager_for_di(va_arg(*argp, int), flags);
	else if (c == 's')
		flager_for_s(va_arg(*argp, char *), flags);
	else if (c == 'c')
		flager_c(va_arg(*argp, int), flags);
	else if (c == 'D')
		flager_for_di(va_arg(*argp, long), flags);
	else if (c == 'C')
		flager_lc(va_arg(*argp, wchar_t), flags);
	else if (c == 'S')
		flager_for_ls(va_arg(*argp, wchar_t *), flags);
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X')
		flager_for_base(va_arg(*argp, unsigned), c, flags);
	else if (c == 'p')
		flager_point(va_arg(*argp, unsigned long long), flags);
	else if ((c == 'd' || c == 'i') && flags->binar == 1)
		flager_for_base(va_arg(*argp, unsigned), c, flags);
}

void	mod_chek_unsig(char c, va_list *argp, t_flags *flags)
{
	if ((c == 'u') && flags->mod == 0)
		flager_for_unsig(va_arg(*argp, unsigned int), flags);
	else if ((c == 'u') && flags->mod == 1)
		flager_for_unsig((unsigned char)va_arg(*argp, unsigned), flags);
	else if ((c == 'u') && flags->mod == 2)
		flager_for_unsig((unsigned short)va_arg(*argp, unsigned int), flags);
	else if (((c == 'u' || c == 'U') && flags->mod == 3) || (c == 'U' && flags->mod < 3))
		flager_for_unsig(va_arg(*argp, unsigned long), flags);
	else if ((c == 'u' || c == 'U') && flags->mod == 4)
		flager_for_unsig(va_arg(*argp, unsigned long long), flags);
	else if ((c == 'u' || c == 'U') && flags->mod == 5)
		flager_for_unsig(va_arg(*argp, intmax_t), flags);
	else if ((c == 'u' || c == 'U') && flags->mod == 6)
		flager_for_unsig(va_arg(*argp, size_t), flags);
}
