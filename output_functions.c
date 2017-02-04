//
// Created by Anton Lushenko on 1/19/17.
//

#include "ft_printf.h"



void write_string(t_format *format, va_list ap)
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
	format->sufix = ft_strnew(sizeof(char) * format->sufix_len);
	ft_strncpy(format->sufix, s, format->sufix_len);
}

void write_wchar_string(t_format *format)
{
	/*
	 * "l" demands conversion to "wchar_t" which is UTF-8 shit
	 */
}

void write_pointer(t_format *format, va_list ap)
{
	/*
	 * # дописывает 0x в начало по идее
	 */
}

void write_char(t_format *format)
{

}

void write_long_char(t_format *format)
{

}

size_t cast_signed(t_format *format, va_list ap)
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

void write_num(t_format *format, va_list ap)
{
	size_t num;
	size_t temp;
	char *mas;
	int i;

	mas = (format->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	format->sufix = ft_strnew(sizeof(char) * 64);
	num = cast_signed(format, ap);
	i = 0;
	temp = 1;
	if ((format->flag & SIGNED) && (num & temp << 63))
	{
		if (format->base == 10)
			format->sufix[i] = '-';
		num = -num;
	}
	i++;
	temp = num;
	while (temp / format->base > 0)
	{
		temp /= format->base;
		i++;
	}
	format->sufix_len = (size_t) i + 1;
	while (num > 0)
	{
		format->sufix[i] = mas[num % format->base];
		num /= format->base;
		i--;
	}
}

void	format_num(t_format *format)
{
	ssize_t len;
	size_t i;

	i = 0;
	len = format->precision - format->sufix_len;

	if (format->sufix[i] != '-')
	{
		if (format->flag & PLUS)
			format->sufix[i] = '+';
		else if (format->flag & SPACE)
			format->sufix[i] = ' ';
		else
		{
			ft_memmove(format->sufix, format->sufix + 1, 63);
			format->sufix_len--;
			i--;
		}
		i++;
	}

}

void 	format_string(t_format *format)
{
	int		c;
	size_t	i;
	ssize_t len;
	char	*str;
	char 	*temp;

	len = format->width - format->sufix_len;
	if (len <= 0)
		return;
	format->sufix_len += len;
	c = ((format->flag & ZEROPAD) && !(format->flag & LEFT)) ? '0' : ' ';
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