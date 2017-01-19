//
// Created by Anton Lushenko on 1/12/17.
//

#include "ft_printf.h"

int skip_atoi(char **s)
{
	size_t i;

	i = 0;
	while (ft_isdigit(**s))
	{
		i = i * 10 + *((*s)++) - '0';
		if (i > INT_MAX)
			return (INT_MAX);
	}
	return ((int) i);
}

void initialise_struct(t_format *format)
{
	/*
	 * продумать значения по умолчанию, как себя ведет прога если они остаются неизмененными.
	 * как поведут себя функции check_ если эти значения изменить
	 */
	format->flag = 0;
	format->width = 0;
	format->precision = 0;
	format->size = 0;
	format->type = 0;
}

int check_flags(char **fmt, t_format *format)
{
	if (**fmt == '-')
		format->flag |= 1;
	else if (**fmt == '+')
		format->flag |= 2;
	else if (**fmt == ' ')
		format->flag |= 4;
	else if (**fmt == '#')
		format->flag |= 8;
	else if (**fmt == '0')
		format->flag |= 16;
	else
		return (0);
	return (1);
}

int check_width(char **fmt, va_list ap, t_format *format)
{
	if (**fmt == '*')
	{
		(*fmt)++;
		format->width = (int) va_arg (ap, int);
		if (format->width < 0)
		{
			format->flag |= 1;
			//не творит ли оно хуню с минимальным интом?
			//если творит, то творит ли оригинальный принтф такую же хуйню?
			format->width = -format->width;
		}
	}
	else if (ft_isdigit(**fmt) && (format->width = skip_atoi(fmt)))
		return (1);
	return (0);
}

int check_precision(char **fmt, va_list ap, t_format *format)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			(*fmt)++;
			format->precision = (int) va_arg (ap, int);
			if (format->precision < 0)
				format->precision = 0;
			return (1);
		}
		else if ((format->precision = skip_atoi(fmt)))
			return (1);
	}
	return (0);
}

int check_size(char **fmt, t_format *format)
{
	size_t len;
	/*
 	* сортануть из в прорядке возрастания/убывания размера, и потом просто маской читать самый крайний
	 *
	 * важно чтобы сначала шли проверки на два символа, иначе при 'l' не зайдет в 'll'
 	*/
	len = 1;
	if (!strncmp(*fmt, "ll", len = 2))
		format->size |= 1;
	else if (!strncmp(*fmt, "hh", len = 2))
		format->size |= 2;
	else if (**fmt == 'h')
		format->size |= 4;
	else if (**fmt == 'l')
		format->size |= 8;
	else if (**fmt == 'j')
		format->size |= 16;
	else if (**fmt == 'z')
		format->size |= 32;
	else
		return (0);
	(*fmt) += len;
	return (1);
}

void check_type(char **fmt, t_format *format)
{
	/*
	 * если спецификатор формата отсутствует?
	 */
	if (**fmt == 's')
		write_string(format);
	if (**fmt == 'S')
		write_wchar_string(format);
	if (**fmt == 'p')
		write_pointer(format);
	if (**fmt == 'd' || **fmt == 'i')
		write_decimal(format);
	if (**fmt == 'c')
		write_char(format);
	if (**fmt == 'C')
		write_long_char(format);
}



