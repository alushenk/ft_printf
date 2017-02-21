/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:26:25 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 19:26:27 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(char **fmt, t_format *format)
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
		return (0);
	return (1);
}

int		check_width(char **fmt, va_list ap, t_format *format)
{
	char *ptr;

	ptr = *fmt;
	if (**fmt == '*')
	{
		format->width = (int)va_arg(ap, int);
		if (format->width < 0)
		{
			format->flag |= 1;
			format->width = -format->width;
		}
		return (1);
	}
	else if (ft_isdigit(**fmt))
	{
		format->width = skip_atoi(&ptr);
		return (ptr - *fmt);
	}
	return (0);
}

int		check_precision(char **fmt, va_list ap, t_format *format)
{
	char *ptr;

	ptr = *fmt;
	if (*ptr == '.')
	{
		ptr++;
		if (*ptr == '*')
		{
			ptr++;
			format->precision = (int)va_arg(ap, int);
		}
		else if (ft_isdigit(*ptr))
		{
			format->precision = skip_atoi(&ptr);
		}
		else
			format->precision = 0;
	}
	return (ptr - *fmt);
}

int		check_size(char **fmt, t_format *format)
{
	int len;

	len = 1;
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
		return (0);
	return (len);
}

int		check_type(char **fmt, t_format *format)
{
	if (!**fmt || !ft_strchr("sSpdDioOuUxXcC", **fmt))
		return (0);
	format->type = **fmt;
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
		format->flag |= SIGNED;
	if (**fmt == 'D' || **fmt == 'S' || **fmt == 'O' ||
		**fmt == 'U' || **fmt == 'E' || **fmt == 'F' ||
		**fmt == 'G' || **fmt == 'A' || **fmt == 'C')
		format->size |= L;
	if (**fmt == 'o' || **fmt == 'O')
		format->base = 8;
	if (**fmt == 'x' || **fmt == 'X')
		format->base = 16;
	if (**fmt == 'x' || **fmt == 'X' || **fmt == 'o' ||
		**fmt == 'O' || **fmt == 'u')
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
