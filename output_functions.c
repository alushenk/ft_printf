//
// Created by Anton Lushenko on 1/19/17.
//

#include "ft_printf.h"

void write_string(t_format *format, va_list ap)
{
	char		*s;
	size_t		len;
	char 		*result;
	size_t		i;
/*
 * don't give a shit about size specifier
 * but, "l" character causes error with "s" type
 */
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (len < format->precision)
		len = format->precision;
	if (len > format->width)
		format->width = len;
	result = ft_strnew(format->width);
	//такой иф не канает, потому шо может быть записано много флагов, от этого меняется число
	if (format->flag == 1)
	{
		ft_strcpy(result, s);
		i = 0;
		while (result[i])
			i++;
		while (i < format->width)
			result[i] = '0';
	}
	if (format->flag == 4)
	{
		ft_strcpy(result, s);
		i = 0;
		while (result[i])
			i++;
		while (i < format->width)
			result[i] = '0';
	}



}

void write_wchar_string(t_format *format)
{

}

void write_pointer(t_format *format)
{

}

void write_decimal(t_format *format, va_list ap)
{
	int num;

	num = (int) va_arg (ap, int);
}

void write_char(t_format *format)
{

}

void write_long_char(t_format *format)
{

}

void	do_print(t_format *format, va_list ap)
{
	if (format->type == 'd' || format->type == 'i')
		write_decimal(format, ap);
}