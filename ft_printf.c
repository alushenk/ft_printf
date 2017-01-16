//
// Created by warto on 1/11/2017.
//

#include "ft_printf.h"

void 	func(char *fmt, va_list ap, char *result)
{
	while (*fmt)
	{
		while (*fmt != '%' && *fmt)
		{
			*result++ = *fmt++;
			g_count++;
		}
		if (*fmt == '\0')
		{
			*result = '\0';
			g_count++;
			break;
		}
		/*
		 * пиздонуть все check_ функции в один иф(одну строку). сделать чтоб они возвращали 1 или 0
		 */
		fmt++;
		check_flags(fmt);
		format->width = check_width(&fmt, ap);
		format->precision = check_precision(&fmt, ap);
		format->size = check_size(&fmt, ap);

		fmt++;
	}
/*
	if(!ft_strcmp(fmt, "%d"))
	{
		int x =(int) va_arg (ap, int);
		ft_putnbr(x);
	}

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

	g_count = 0;
	g_flag = 0;
	format = (t_format*)malloc(sizeof(t_format));
	initialise_struct(format);

    va_start(ap, fmt);
	func(fmt, ap, result);
    va_end(ap);
	ft_putstr(result);
	return (g_count);
}