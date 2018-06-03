/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unistr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatiaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:30:29 by kpatiaka          #+#    #+#             */
/*   Updated: 2018/05/21 19:30:30 by kpatiaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_unistr(wchar_t *unistr, t_flags *flags)
{
	int n;
	int temp;

	temp = -1;
	while (unistr[++temp])
	{
		if (get_unicode_char_len(unistr[temp]) == -1)
		{
			flags->total = -1;
			return (-1);
		}
	}
	temp = -1;
	while (unistr[++temp])
	{
		n = put_unic(unistr[temp]);
		flags->total = (n == -1) ? -1 : (flags->total + n);
	}
	return (0);
}
