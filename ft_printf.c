//
// Created by warto on 1/11/2017.
//

#include "ft_printf.h"

size_t		get_len(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	return (i);
}

void 		func(char *fmt, va_list ap, char *result, t_format *format)
{
	char	*ptr;
	size_t	prefix_size;

	while (*fmt)
	{
		if ((prefix_size = get_len(fmt)))
		{
			format->prefix = ft_strnew(prefix_size);
			ft_strncpy(format->prefix, fmt, prefix_size);
		}
		fmt += prefix_size;
		if (*fmt == '\0')
			break;
		fmt++;
		while(check_flags(&fmt, format))
			fmt++;
		while(check_width(&fmt, ap, format));
		while (check_precision(&fmt, ap, format));
		while ((check_size(&fmt, format)));
		check_type(&fmt, format);
		do_print(format, ap);
		fmt++;
	}
/*
	if(!ft_strcmp(fmt, "%s"))
	{
		char *p = va_arg (ap, char *);
		ft_putstr(p);
	}
*/
}

int    ft_printf(char *fmt, ...)
{
    va_list ap;
	/*
	 * реализовать расширение буфера с помощью связанных списков
	 * или тупо расширять с помощью малоков и буфера
	 *
	 * когда указатель дойдет до конца - расширить или создать еще один элемент размером с буфер
	 */
	char	result[2048];
	t_format	*format;

	format = NULL;
	initialise_struct(&format);

    va_start(ap, fmt);
	func(fmt, ap, result, format);
    va_end(ap);
	//ft_putstr(result);
	return (0);
}