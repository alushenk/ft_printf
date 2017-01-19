//
// Created by warto on 1/11/2017.
//

#include "ft_printf.h"

void 	func(char *fmt, va_list ap, char *result, t_format *format)
{
	char	*ptr;

	while (*fmt)
	{
		while (*fmt != '%' && *fmt)
		{
			*result++ = *fmt++;
		}
		if (*fmt == '\0')
		{
			*result = '\0';
			break;
		}
		fmt++;
		while(check_flags(&fmt, format))
			fmt++;
		while(check_width(&fmt, ap, format));
		while (check_precision(&fmt, ap, format));
		while ((check_size(&fmt, format)));
		check_type(&fmt, format);
		fmt++;
	}
/*
	if(!ft_strcmp(fmt, "%s"))
	{
		char *p = va_arg (ap, char *);
		ft_putstr(p);
	}
*/
}

int    ft_printf(char *fmt, ...)
{
    va_list ap;
	char	result[2048];
	t_format	*format;

	format = (t_format*)malloc(sizeof(t_format));
	initialise_struct(format);

    va_start(ap, fmt);
	func(fmt, ap, result, format);
    va_end(ap);
	//ft_putstr(result);
	return (0);
}