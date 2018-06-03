/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flager_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:47:25 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/22 14:47:28 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flager_c(char c, t_flags *flags)
{
	int		len;

	len = 0;
	if (flags->minus == 1)
		flags->total += write(1, &c, 1);
	if (flags->width != -1 && flags->width > len)
		while (++len < flags->width)
			flags->total += (flags->zero == 1) ? \
			write(1, "0", 1) : write(1, " ", 1);
	if (flags->minus != 1)
		flags->total += write(1, &c, 1);
}

void	flager_for_s(char *s, t_flags *flags)
{
	int		len;
	int		i;
	int		p;

	len = 0;
	i = 0;
	if (s)
		while (s[len])
			len++;
	else
		len = 0;
	p = (s == NULL && flags->precision > 0 \
		&& flags->precision < 7) ? flags->precision : 6;
	p = (s == NULL) ? p : 0;
	if (flags->precision != 0)
		len = (flags->precision < len) ? flags->precision : len;
	if (flags->width != -1 && flags->minus == 0 && flags->width > len)
		while ((len + i + p) < flags->width)
			i += (flags->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
	flags->total += (s == NULL) ? write(1, "(null)", p) : write(1, s, len);
	if (flags->width != -1 && flags->minus == 1 && flags->width > len)
		while ((len + i) < flags->width)
			i += (flags->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
	flags->total += (i);
}

void	flager_lc(wchar_t c, t_flags *flags)
{
	int		len;

	len = get_unicode_char_len(c);
	if (flags->minus == 1)
		flags->total += put_unic(c);
	if (flags->width != -1 && flags->width > len)
		while (len < flags->width)
		{
			flags->total += (flags->zero == 1) ? write(1, "0", 1) \
			: write(1, " ", 1);
			len++;
		}
	if (flags->minus != 1)
		flags->total += put_unic(c);
}

void	flager_for_ls(wchar_t *unistr, t_flags *flags)
{
	int		len;
	int		i;
	int		temp;

	len = 0;
	i = 0;
	temp = -1;
	while (unistr[++temp])
		len += get_unicode_char_len(unistr[temp]);
	if (flags->width != -1 && flags->minus == 0 && flags->width > len)
		while ((len + i) < flags->width)
			i += (flags->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
	put_unistr(unistr, flags);
	if (flags->width != -1 && flags->minus == 1 && flags->width > len)
		while ((len + i) < flags->width)
			i += (flags->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
	flags->total += i;
}
