//
// Created by Anton Lushenko on 1/12/17.
//

#include "ft_printf.h"

void initialise_struct(t_format *format)
{
	format->width = -1;
	format->precision = -1;
	ft_bzero(format->size, 3);
}

void check_flags(char *fmt)
{
	if (*fmt == '-')
		g_flag |= 1;
	else if (*fmt == '+')
		g_flag |= 2;
	else if (*fmt == ' ')
		g_flag |= 4;
	else if (*fmt == '#')
		g_flag |= 8;
	else if (*fmt == '0')
		g_flag |= 16;
}

int check_width(char **fmt, va_list ap)
{
	int result;
	char *str;

	str = *fmt;
	result = -1;
	if (*str == '*')
	{
		str++;
		result = (int) va_arg (ap, int);
		if (result < 0)
		{
			g_flag |= 1;
			//не творит ли оно хуню с минимальным интом?
			//если творит, то творит ли оригинальный принтф такую же хуйню?
			result = -result;
		}
	}
	else
		while (ft_isdigit(*str))
		{
			result = result * 10 + (**fmt - '0');
			str++;
		}
	*fmt = str;
	return (result);
}

int check_precision(char **fmt, va_list ap)
{
	int result;
	char *str;

	str = *fmt;
	result = -1;
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			str++;
			result = (int) va_arg (ap, int);
			if (result < 0)
			{
				//не творит ли оно хуню с минимальным интом?
				//если творит, то творит ли оригинальный принтф такую же хуйню?
				result = -result;
			}
		}
		else
			while (ft_isdigit(*str))
			{
				result = result * 10 + (**fmt - '0');
				str++;
			}
		*fmt = str;
		return (result);
	}
}

char *check_size(char **fmt, va_list ap)
{
	char *result;

	result = ft_strnew(3);

}



