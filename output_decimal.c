//
// Created by Anton Lushenko on 1/23/17.
//

#include "ft_printf.h"

/*
 * signed char
 */
void 	write_d_h(t_format *format, va_list ap)
{
	short result;

	result = (short) va_arg(ap, short);
	format->sufix = ft_itoa(result);
}

void 	write_d_hh(t_format *format, va_list ap)
{
	char result;

	result = (char) va_arg(ap, char);
	format->sufix = ft_itoa(result);
}

void	write_d_long(t_format *format, va_list ap)
{
	long result;

	result = (long) va_arg(ap, long);

}