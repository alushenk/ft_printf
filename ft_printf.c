/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:40:36 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 16:40:40 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_len(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	return (i);
}

static size_t cast_signed(t_format *format, va_list ap)
{
	size_t result;

	result = (format->size & Z) ? (size_t) va_arg(ap, size_t) :
			 (format->size & J) ? (uintmax_t) va_arg(ap, uintmax_t) :
			 (format->size & LL) ? (unsigned long long) va_arg(ap, unsigned long long) :
			 (format->size & L) ? (unsigned long) va_arg(ap, unsigned long) :
			 (format->size & U) ? (unsigned) va_arg(ap, unsigned) :
			 (format->size & H) ? (short) va_arg(ap, int) :
			 (format->size & HH) ? (char) va_arg(ap, int) :
			 (size_t) va_arg(ap, int);

	return (result);
}

size_t do_print(t_format *format, va_list ap)
{
	/*
	 * сделать начальный иф для чара? или писать его как обычное число преобразованое в строку(атои)
	 *
	 * для флоата тоже, или пихануть проверку в атоях
	 */
	if (format->type == 's')
		write_string(format, ap);
	else if (format->type)
	{
		write_num(format, ap);
		format_num_prefix(format);
		format_num(format);
	}
	format_string(format);
	ft_putstr(format->prefix);
	ft_putstr(format->sufix);

	return (format->prefix_len + format->sufix_len);
	return (0);
}

int		func(char *fmt, va_list ap, t_format *format)
{
	size_t	result;

	result = 0;
	while (*fmt)
	{
		initialise_struct(&format);
		if ((format->prefix_len = get_len(fmt)))
		{
			format->prefix = ft_strnew(format->prefix_len);
			ft_strncpy(format->prefix, fmt, format->prefix_len);
		}
		fmt += format->prefix_len;
		fmt = (*fmt) ? fmt + 1 : fmt;
		while (*fmt)
		{
			check_flags(&fmt, format);
			check_width(&fmt, ap, format);
			check_precision(&fmt, ap, format);
			check_size(&fmt, format);
			if (check_type(&fmt, format))
				break ;
		}
		result += do_print(format, ap);
	}
	return ((int)result);
}

int		ft_printf(char *fmt, ...)
{
	va_list		ap;
	t_format	*format;
	int			result;

	format = NULL;
	va_start(ap, fmt);
	result = func(fmt, ap, format);
	va_end(ap);
	if (result > INT_MAX)
		result = -1;
	return (result);
}
