//
// Created by Anton Lushenko on 1/12/17.
//

#include "ft_printf.h"

void initialise_struct(t_format *format)
{
	format->flag = 0;
	format->width = -1;
	format->precision = -1;

	format->size = ft_strnew(2);
	ft_bzero(format->size, 3);
}

int check_flags(char *fmt, t_format *format)
{
	if (*fmt == '-')
		format->flag |= 1;
	else if (*fmt == '+')
		format->flag |= 2;
	else if (*fmt == ' ')
		format->flag |= 4;
	else if (*fmt == '#')
		format->flag |= 8;
	else if (*fmt == '0')
		format->flag |= 16;
	else
		return (0);
	return (1);
}

int check_width(char **fmt, va_list ap, t_format *format)
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
			format->flag |= 1;
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
				result = 0;
			}
		}
		else
			while (ft_isdigit(*str))
			{
				result = result * 10 + (**fmt - '0');
				str++;
			}
	}
	*fmt = str;
	return (result);
}

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



