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

int			wchar_length(wchar_t symbol)
{
	int		len;

	len = 0;
	if (symbol >= 0 && symbol <= 127)
		len = 1;
	else if (symbol >= 128 && symbol <= 2047)
		len = 2;
	else if (symbol >= 2048 && symbol <= 65535)
		len = 3;
	else if (symbol >= 65536 && symbol <= 2097151)
		len = 4;
	else if (symbol >= 2097152 && symbol <= 67108863)
		len = 5;
	else if (symbol >= 67108864 && symbol <= 2147483647)
		len = 6;
	return (len);
}

char		*char_to_chars(wchar_t symbol, t_format *format, int len)
{
	char	*str;
	char 	*result;
	char	num;
	int		i;
	int 	j;
	char	mask;

	str = ft_strnew(len);
	i = 0;
	mask = 127;
	while (i < len)
	{
		num = (char)symbol;
		if ((i + 1) == len)
		{
			num &= mask >> i;
			if (i)
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
	result = ft_strnew(len);
	j = 0;
	while (--i >= 0)
	{
		result[j] = str[i];
		j++;
	}
	free(str);
	format->sufix_len += len;
	return (result);
}

void		chars_to_chars(t_format *format, va_list ap)
{
	wchar_t *symbol;
	char	**result;
	char 	*temp;
	ssize_t i;
	ssize_t	len;

	symbol = va_arg(ap, wchar_t*);
	i = 0;
	while (symbol[i])
		i++;
	result = (char**)malloc(sizeof(char*) * i);
	i = 0;
	len = 0;
	while(symbol[i])
	{
		len += wchar_length(symbol[i]);
		if (format->precision > 0 && len > format->precision)
			break ;
		result[i] = char_to_chars(symbol[i], format, wchar_length(symbol[i]));
		i++;
	}
	while (--i >= 0)
	{
		temp = ft_strdup(format->sufix);
		free(format->sufix);
		format->sufix = ft_strjoin(result[i], temp);
		free(result[i]);
		free(temp);
	}
	free(result);
}
