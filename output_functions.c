//
// Created by Anton Lushenko on 1/19/17.
//

#include "ft_printf.h"

void write_string(t_format *format, va_list ap)
{
	char		*s;
	size_t		len;
	size_t		i;
	char 		c;
/*
 * don't give a shit about size specifier
 * but, "l" character causes error with "s" type
 */
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	/*
	 * проверка на INT_MAX
	 */
	if (len > format->width)
		format->width = len;
	if (format->precision && len > format->precision)
		len = format->precision;
	format->sufix = ft_strnew(format->width);
	c = format->flag & ZEROPAD ? '0' : ' ';
	i = 0;
	if (!(format->flag & LEFT))
		while (len < format->width--)
		{
			format->sufix[i] = c;
			i++;
		}
	else
		i += len;
	ft_strncat(format->sufix, s, len);
	while (len < format->width--)
		format->sufix[i++] = ' ';


	if (format->flag == 4)
	{
		ft_strcpy(format->sufix, s);
		i = 0;
		while (format->sufix[i])
			i++;
		while (i < format->width)
			format->sufix[i] = '0';
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
	if (format->type == 's' || format->type == 'S')
		write_string(format, ap);

	ft_putstr(format->prefix);
	ft_putstr(format->sufix);
}