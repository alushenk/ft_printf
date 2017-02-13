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

size_t	cast_signed(t_format *format, va_list ap)
{
	size_t result;

	if (format->size & Z)
		result = (size_t)va_arg(ap, size_t);
	else if (format->size & J)
		result = (uintmax_t)va_arg(ap, uintmax_t);
	else if (format->size & LL)
		result = (unsigned long long)va_arg(ap, unsigned long long);
	else if (format->size & L)
		result = (unsigned long)va_arg(ap, unsigned long);
	else if (format->size & U)
		result = (unsigned)va_arg(ap, unsigned);
	else if (format->size & H)
		result = (short)va_arg(ap, int);
	else if (format->size & HH)
		result = (char)va_arg(ap, int);
	else
		result = (size_t)va_arg(ap, int);
	return (result);
}

size_t	do_print(t_format *format, va_list ap)
{
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
}

int		func(char *fmt, va_list ap, t_format **format)
{
	size_t	result;
	int		skip;

	result = 0;
	skip = 0;
	while (*fmt)
	{
		initialise_struct(format);
		if (((*format)->prefix_len = get_len(fmt)))
		{
			(*format)->prefix = ft_strnew((*format)->prefix_len);
			ft_strncpy((*format)->prefix, fmt, (*format)->prefix_len);
		}
		fmt += (*format)->prefix_len;
		fmt = (*fmt) ? fmt + 1 : fmt;
		while (*fmt)
		{
			if (check_type(&fmt, *format))
				break ;
			if ((skip = check_flags(&fmt, *format)) ||
				(skip = check_width(&fmt, ap, *format)) ||
				(skip = check_precision(&fmt, ap, *format)) ||
				(skip = check_size(&fmt, *format)))
				fmt += skip;
			else
			{
				add_symbol(*format, *fmt);
				fmt++;
				break ;
			}
		}
		result += do_print(*format, ap);
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
	result = func(fmt, ap, &format);
	va_end(ap);
	if (result > INT_MAX)
		result = -1;
	if (format)
	{
		if (format->prefix)
			free(format->prefix);
		if (format->sufix)
			free(format->sufix);
		if (format->num_prefix)
			free(format->num_prefix);
		free(format);
	}
	return (result);
}
