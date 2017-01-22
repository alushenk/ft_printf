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
	size_t	prefix_len;

	while (*fmt)
	{
		initialise_struct(&format);
		if ((prefix_len = get_len(fmt)))
		{
			format->prefix = ft_strnew(prefix_len);
			ft_strncpy(format->prefix, fmt, prefix_len);
			format->prefix_len = prefix_len;
		}
		fmt += prefix_len;
		if (*fmt != '\0')
		{
			fmt++;
			while(check_flags(&fmt, format))
				fmt++;
			while(check_width(&fmt, ap, format));
			while (check_precision(&fmt, ap, format));
			while ((check_size(&fmt, format)));
			check_type(&fmt, format);
		}
		do_print(format, ap);
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
    va_start(ap, fmt);
	func(fmt, ap, result, format);
    va_end(ap);
	//ft_putstr(result);
	return (0);
}