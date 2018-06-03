/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:34:42 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/17 19:34:44 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_unicode_char_len(wchar_t c)
{
	if (c < 0 || c > 1114111 || (c >= 55296 && c <= 57343))
		return (-1);
	else if (c <= 127 || (c <= 255 && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	return (4);
}

int		put_unic(wchar_t c)
{
	char	a[4];

	if ((get_unicode_char_len(c)) == -1)
		return (-1);
	else if ((get_unicode_char_len(c)) == 1)
		a[0] = c;
	else if ((get_unicode_char_len(c)) == 2)
	{
		a[0] = (c >> 6) | 192;
		a[1] = (c & 63) | 128;
	}
	else if ((get_unicode_char_len(c)) == 3)
	{
		a[0] = (c >> 12) | 224;
		a[1] = ((c >> 6) & 63) | 128;
		a[2] = (c & 63) | 128;
	}
	else if ((get_unicode_char_len(c)) == 4)
	{
		a[0] = (c >> 18) | 240;
		a[1] = (c >> 12 & 63) | 128;
		a[2] = ((c >> 6) & 63) | 128;
		a[3] = (c & 63) | 128;
	}
	return (write(1, &a, get_unicode_char_len(c)));
}
