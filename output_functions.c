//
// Created by Anton Lushenko on 1/19/17.
//

#include "ft_printf.h"

void write_string(t_format *format, va_list ap)
{
	char *s;
	size_t len;
	size_t i;
	char c;
/*
 * don't give a shit about size specifier
 * but, "l" character causes no output
 *
 * "l" demands conversion to "wchar_t" which is UTF-8 shit (the next function after this)
 *
 * sp no
 * +  no
 * #  no
 * 0  yes
 * -  yes
 */
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	/*
	 * проверка на INT_MAX
	 */
	if (len > format->width)
		format->width = len;
	format->sufix_len = format->width;
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

void write_pointer(t_format *format, va_list ap)
{
	/*
	 * # дописывает 0x в начало по идее
	 */
}

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
void write_char(t_format *format)
{

}

void write_long_char(t_format *format)
{

}


/*
void initialise_array(void (*foo[])(t_format* , va_list))
{
	foo[0] = &write_d_h;
	foo[1] = &write_d_hh;

}
*/
ssize_t cast_signed(t_format *format, va_list ap)
{
	ssize_t result;
/*
 * если зохавать из va_arg больше/меньше байт чем там должно быть, мы зацепим следующий параметр?
 *s
 * че будет если этим считать  unsigned тип?
 */
	if (format->flag & SIGNED)
	{
		result = (format->size & LL) ? (long long) va_arg(ap, long long) :
				 (format->size & L) ? (long) va_arg(ap, long) :
				 (format->size & H) ? (short) va_arg(ap, short) :
				 (format->size & HH) ? (char) va_arg(ap, char) :
				 (int) va_arg(ap, int);
	}
	else
	{
		result = (format->size & LL) ? (unsigned long long) va_arg(ap, unsigned long long) :
				 (format->size & L) ? (unsigned long) va_arg(ap, unsigned long) :
				 (format->size & H) ? (unsigned short) va_arg(ap, unsigned short) :
				 (format->size & HH) ? (unsigned char) va_arg(ap, unsigned char) :
				 (unsigned int) va_arg(ap, unsigned int);
	}
	return (result);
}

void write_num(t_format *format, va_list ap)
{
	size_t num;
	ssize_t temp;
	char *mas;
	int i;

	mas = "0123456789abcdef";
	if (format->base < 2 || format->base > 16 || !(format->sufix = ft_strnew(sizeof(char) * 64)))
		return;
	temp = cast_signed(format, ap);
	num = (size_t) temp;
	i = 0;
	if (temp < 0)
	{
		if (format->base == 10)
		{
			format->sufix[i] = '-';
			i++;
		}
		//if (format->flag & SIGNED)
			num = (size_t) -temp;
	}
	temp = num;
	while (temp / format->base > 0)
	{
		temp /= format->base;
		i++;
	}
	while (num > 0)
	{
		format->sufix[i] = mas[num % format->base];
		num /= format->base;
		i--;
	}
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
	else if (format->type == 'p')
		write_pointer(format, ap);
	else if (format->type)
		write_num(format, ap);
	ft_putstr(format->prefix);
	ft_putstr(format->sufix);
	/*
	 * так как ft_strlen не проверяет на NULL то делаю это здесь
	 */
	return ((format->prefix ? ft_strlen(format->prefix) : 0) + (format->sufix ? ft_strlen(format->sufix) : 0));
	return (0);
}