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

int			wchar_length(wint_t symbol)
{
	int		len;

	len = 0;
	if (symbol <= 127)
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

static int	split_wchar(int len, wint_t symbol, char *str, char mask)
{
	char	num;
	int		i;

	i = 0;
	while (i < len)
	{
		num = (char)symbol;
		if ((i + 1) == len)
		{
			num &= (mask >> i);
			if (i)
				num |= ((~mask) >> i);
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
	return (i);
}

char		*wchar_to_str(wint_t symbol, t_format *format, int len)
{
	char	*str;
	char	*result;
	int		i;
	int		j;

	str = ft_strnew(len);
	result = ft_strnew(len);
	i = split_wchar(len, symbol, str, 127);
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

void		write_wstr(wchar_t *string, t_format *format, int i)
{
	ssize_t	len;
	char	**result;
	char	*temp;

	result = (char**)malloc(sizeof(char*) * i);
	len = 0;
	i = 0;
	while (string[i])
	{
		len += wchar_length(string[i]);
		if (format->precision > 0 && len > format->precision)
			break ;
		result[i] = wchar_to_str(string[i], format, wchar_length(string[i]));
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

void		wstr_to_str(t_format *format, va_list ap)
{
	wchar_t *string;
	ssize_t i;

	string = va_arg(ap, wchar_t*);
	if (string == NULL)
	{
		format->sufix = ft_strdup("(null)");
		return ;
	}
	i = 0;
	while (string[i])
		i++;
	write_wstr(string, format, i);
}
