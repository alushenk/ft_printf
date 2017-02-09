/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:41:21 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 16:41:24 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void write_string(t_format *format, va_list ap)
{
	char *s;
/*
 * sp no
 * +  no
 * #  no
 * 0  yes
 * -  yes
 */
	s = va_arg(ap, char *);
	format->sufix_len = (int)ft_strlen(s);
	/*
	 * проверка на INT_MAX
	 */
	if (format->precision >= 0 && format->sufix_len > format->precision)
		format->sufix_len = format->precision;
	/*
	 * можно не делать копию, а просто присвоить ссылку
	 */
	format->sufix = ft_strnew(sizeof(char) * format->sufix_len);
	ft_strncpy(format->sufix, s, format->sufix_len);
}

static size_t cast_signed(t_format *format, va_list ap)
{
	size_t result;

	result = (format->size & Z) ? (size_t) va_arg(ap, size_t) :
			 (format->size & J) ? (uintmax_t) va_arg(ap, uintmax_t) :
			 (format->size & LL) ? (unsigned long long) va_arg(ap, unsigned long long) :
			 (format->size & L) ? (unsigned long) va_arg(ap, unsigned long) :
			 (format->size & U) ? (unsigned) va_arg(ap, unsigned) :
			 (format->size & H) ? (short) va_arg(ap, int) :
			 (format->size & HH) ? (char) va_arg(ap, int) :
			 (size_t) va_arg(ap, int);

	return (result);
}

static void write_num(t_format *format, va_list ap)
{
	size_t num;
	size_t temp;
	char *mas;
	int i;

	mas = (format->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	num = cast_signed(format, ap);
	temp = 1;
	if ((format->flag & SIGNED) && (num & temp << 63))
	{
		if (format->base == 10)
			format->num_prefix[0] = '-';
		num = -num;
	}
	temp = num;
	i = (num) ? 0 : 1;
	while (temp > 0)
	{
		temp /= format->base;
		i++;
	}
	format->sufix = ft_strnew(sizeof(char) * (i + 1));
	format->sufix_len = i;
	while (--i >= 0)
	{
		format->sufix[i] = mas[num % format->base];
		num /= format->base;
	}
}

void	format_num_prefix(t_format *format)
{
	if (!ft_strncmp(format->sufix, "0\0", 2) && format->precision == 0)
		format->sufix[0] = ' ';
	if (format->num_prefix[0] == 0 && (format->flag & SIGNED))
	{
		if (format->flag & PLUS)
			format->num_prefix[0] = '+';
		else if (format->flag & SPACE)
			format->num_prefix[0] = ' ';
		if (format->sufix[0] == ' ')
		{
			ft_strcpy(format->sufix, format->num_prefix);
			ft_bzero(format->num_prefix, 2);
		}
	}
	if (format->flag & HASH)
	{
		if (format->base == 16)
		{
			format->num_prefix[0] = '0';
			format->num_prefix[1] = (format->type == 'X') ? 'X' : 'x';
		}
		if (format->base == 8)
			format->num_prefix[0] = '0';
	}
}

void	format_num(t_format *format)
{
	ssize_t len;
	ssize_t	i;
	char	*str;

	len = (format->precision > format->sufix_len) ? format->precision : format->sufix_len;
	if (format->precision == -1 && format->width > len && !(format->flag & LEFT))
		len = format->width;
	i = 0;
	if (format->base == 16 && (format->flag & HASH))
		len += 2;
	str = ft_strnew(len + 1);
	while(format->num_prefix[i])
	{
		str[i] = format->num_prefix[i];
		i++;
	}
	while(format->sufix_len < (len - i))
	{
		str[i] = '0';
		i++;
	}
	format->sufix_len += i;
	ft_strcpy(str + i, format->sufix);
	free(format->sufix);
	format->sufix = str;
}

void 	format_string(t_format *format)
{
	int		c;
	ssize_t	i;
	ssize_t len;
	char	*str;
	char 	*temp;

	if ((len = format->width - format->sufix_len) <= 0 || format->width < format->precision)
		return;
	format->sufix_len += len;
	c = (format->flag & ZEROPAD && !(format->flag & LEFT)) ? '0' : ' ';
	if (format->type != 'S' && format->type != 's' && format->precision != -1)
		c = ' ';
	str = ft_strnew(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	temp = ft_strdup(format->sufix);
	free(format->sufix);
	if (format->flag & LEFT)
		format->sufix = ft_strjoin(temp, str);
	else
		format->sufix = ft_strjoin(str, temp);
	free(temp);
}

size_t do_print(t_format *format, va_list ap)
{
	/*
	 * сделать начальный иф для чара? или писать его как обычное число преобразованое в строку(атои)
	 *
	 * для флоата тоже, или пихануть проверку в атоях
	 */
	if (format->type == 's')
		write_string(format, ap);
	else if (format->type)
	{
		write_num(format, ap);
		format_num_prefix(format);
		format_num(format);
	}

	format_string(format);
	/*
	 * если длинна всего барахла не превышает максимальный инт
	 */
	ft_putstr(format->prefix);
	ft_putstr(format->sufix);

	return (format->prefix_len + format->sufix_len);
	return (0);
}
