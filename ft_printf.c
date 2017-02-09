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

size_t get_len(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	return (i);
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
		if (*fmt)
			fmt++;
		while(*fmt)
		{
			check_flags(&fmt, format);
			check_width(&fmt, ap, format);
			check_precision(&fmt, ap, format);
			check_size(&fmt, format);
			if (check_type(&fmt, format))
				break;
		}
		result += do_print(format, ap);
	}
	if (result > INT_MAX)
		return (-1);
	return ((int)result);
}

int ft_printf(char *fmt, ...)
{
	va_list ap;
	t_format *format;
	int result;

	format = NULL;
	va_start(ap, fmt);
	result = func(fmt, ap, format);
	va_end(ap);

	return (result);
}
