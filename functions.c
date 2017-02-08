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

void initialise_struct(t_format **format)
{
	/*
	 * продумать значения по умолчанию, как себя ведет прога если они остаются неизмененными.
	 * как поведут себя функции check_ если эти значения изменить
	 *
	 * нету смысла фришить сам поинтер на структуру, можно тупо его обнулять
	 */
	if (!*format)
	{
		*format = (t_format *) malloc(sizeof(t_format));
		(*format)->prefix = NULL;
		(*format)->sufix = NULL;
		(*format)->num_prefix = ft_strnew(2);
	}
	(*format)->flag = 0;
	(*format)->width = 0;
	(*format)->precision = -1;
	(*format)->size = 0;
	(*format)->type = 0;
	(*format)->base = 10;
	(*format)->prefix_len = 0;
	(*format)->sufix_len = 0;
	if ((*format)->num_prefix)
		ft_bzero((*format)->num_prefix, 2);
	if ((*format)->prefix)
		free((*format)->prefix);
	(*format)->prefix = NULL;
	if ((*format)->sufix)
		free((*format)->sufix);
	(*format)->sufix = NULL;
}

void check_flags(char **fmt, t_format *format)
{
	if (**fmt == '-')
		format->flag |= LEFT;
	else if (**fmt == '+')
		format->flag |= PLUS;
	else if (**fmt == ' ')
		format->flag |= SPACE;
	else if (**fmt == '#')
		format->flag |= HASH;
	else if (**fmt == '0')
		format->flag |= ZEROPAD;
	else
		return;
	(*fmt)++;
}

void check_width(char **fmt, va_list ap, t_format *format)
{
	if (**fmt == '*')
	{
		format->width = (int) va_arg (ap, int);
		if (format->width < 0)
		{
			format->flag |= 1;
			//не творит ли оно хуню с минимальным интом?
			//если творит, то творит ли оригинальный принтф такую же хуйню?
			format->width = -format->width;
		}
	}
	else if (ft_isdigit(**fmt))
		format->width = skip_atoi(fmt);
}

void check_precision(char **fmt, va_list ap, t_format *format)
{
	ssize_t result;

	result = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			result = (int) va_arg (ap, int);
			(*fmt)++;
		}
		else
			result = skip_atoi(fmt);
		if (result < 0)
			format->precision = -1;
		else
			format->precision = result;
	}
}

void check_size(char **fmt, t_format *format)
{
	size_t len;

	len = 1;
	/*
	 * "&&" в ифах - мастерство укорачивать код костылями
	 */
	if (**fmt == 'z')
		format->size |= Z;
	else if (**fmt == 'j')
		format->size |= J;
	else if (!strncmp(*fmt, "ll", 2) && len++)
		format->size |= LL;
	else if (**fmt == 'l')
		format->size |= L;
	else if (!strncmp(*fmt, "hh", 2) && len++)
		format->size |= HH;
	else if (**fmt == 'h')
		format->size |= H;
	else
		return;
	(*fmt) += len;
}

int check_type(char **fmt, t_format *format)
{
	char *type;

	type = "sSpdDioOuUxXcC";
	if (!**fmt || !ft_strchr(type, **fmt))
		return (0);
	format->type = **fmt;
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
		format->flag |= SIGNED;
	if (**fmt == 'D' || **fmt == 'S' || **fmt == 'O' || **fmt == 'U' || **fmt == 'E' ||
		**fmt == 'F' || **fmt == 'G' || **fmt == 'A' || **fmt == 'C')
		format->size |= L;
	if (**fmt == 'o' || **fmt == 'O')
		format->base = 8;
	if (**fmt == 'x' || **fmt == 'X')
		format->base = 16;
	//делать для U?
	if (**fmt == 'x' || **fmt == 'X' || **fmt == 'o' || **fmt == 'O' || **fmt == 'u')
		format->size |= U;
	if (**fmt == 'p')
	{
		format->base = 16;
		format->size |= Z;
		format->flag |= HASH;
	}
	(*fmt)++;
	return (1);
}



