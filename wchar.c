/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 20:11:44 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/13 20:11:46 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_char(t_format *format, va_list ap)
{
	char	*str;
	int		symbol;
	char	num;
	int		i;
	int 	j;
	unsigned char mask;

	symbol = (int)va_arg(ap, int);

	if (symbol >= 0 && symbol <= 127)
		format->sufix_len = 1;
	else if (symbol >= 128 && symbol <= 2047)
		format->sufix_len = 2;
	else if (symbol >= 2048 && symbol <= 65535)
		format->sufix_len = 3;
	else if (symbol >= 65536 && symbol <= 2097151)
		format->sufix_len = 4;
	else if (symbol >= 2097152 && symbol <= 67108863)
		format->sufix_len = 5;
	else if (symbol >= 67108864 && symbol <= 2147483647)
		format->sufix_len = 6;

	str = ft_strnew(format->sufix_len);
	i = 0;
	mask = 127;
	while (i < format->sufix_len)
	{
		num = (char)symbol;
		if ((i + 1) == format->sufix_len)
		{
			num &= mask >> i;
			num |= (~mask) >> i;
			str[i] = num;
		}
		else
		{
			num &= 63;
			num |= 128;
			str[i] = num;
		}
		symbol >>= 6;
		i++;
	}
	format->sufix = ft_strnew(format->sufix_len);
	j = 0;
	while (--i >= 0)
	{
		format->sufix[j] = str[i];
		j++;
	}
}
