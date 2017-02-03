//
// Created by Anton Lushenko on 1/19/17.
//
#include "ft_printf.h"

/*
char *check_size(char **fmt, va_list ap)
{
	char *str;
	char *result;

	result = NULL;
	str = *fmt;
	if (*str == 'h')
		result = ft_strdup("h");
	if (!strncmp(str, "hh", 2))
		result = ft_strdup("hh");
	if (*str == 'l')
		result = ft_strdup("l");
	if (!strncmp(str, "ll", 2))
		result = ft_strdup("ll");
	if (*str == 'j')
		result = ft_strdup("j");
	if (*str == 'z')
		result = ft_strdup("z");
	if (!result)
		return (NULL);
	str += ft_strlen(result);
	*fmt = str;
	return (result);
}
 */

/*
void initialise_array(void (*foo[])(t_format* , va_list))
{
	foo[0] = &write_d_h;
	foo[1] = &write_d_hh;

}
*/

/*
void write_decimal(t_format *format, va_list ap)
{
	int num;
	size_t i;
	void (*foo[6])(t_format *a, va_list b);

	initialise_array(foo);
	i = 0;
	num = 0;
	while(!(format->size & (1 << i)) && i < 6)
		i++;
	if (i == 6)
		num = (int) va_arg (ap, int);
	else
		foo[i](format, ap);
}
*/

/*
	result = (format->size & LL) ? (long long) va_arg(ap, long long) :
			 (format->size & L) ? (long) va_arg(ap, long) :
			 (format->size & H) ? (short) va_arg(ap, short) :
			 (format->size & HH) ? (char) va_arg(ap, char) :
			 (int) va_arg(ap, int);
*/