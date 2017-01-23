//
// Created by warto on 1/11/2017.
//

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
	char	*ptr;
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
		if (*fmt != '\0')
		{
			fmt++;
			while (check_flags(&fmt, format))
				fmt++;
			while (check_width(&fmt, ap, format));
			while (check_precision(&fmt, ap, format));
			while ((check_size(&fmt, format)));
			check_type(&fmt, format);
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