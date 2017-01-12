//
// Created by warto on 1/11/2017.
//

#include "ft_printf.h"

int     in_managed_types(char type)
{
    if (type == 's' || type == 'd' || type == 'c')
        return(1);
    return(0);
}

size_t count_outputs(char *str)
{
    size_t count;

    count = 0;
    while(*str)
    {
        if (*str == '%')
        {
            str++;
            if (!in_managed_types(*str))
                return (0);
            count++;
        }
        str++;
    }
    return (count);
}

char     find_next(char *str, size_t len)
{
    while (*str != '%' && *str)
        str++;
    if (*str)
    {

    }
    return (0);
}

char	*get_string(char type, va_list ap)
{
	if (type == 's')
		return (va_arg(ap, char*));
	if (type == 'd')
		return (ft_itoa(va_arg(ap, int)));
}

int    ft_printf(char *fmt, ...)
{
    va_list ap;
    va_list copy;
    size_t  count;
    size_t  i;
    char    c;
	char	*result;
	char 	*temp;

	result = NULL;
    if (!(count = count_outputs(fmt)))
    {
        ft_putendl(fmt);
        exit(0);
    }
    va_start(ap, fmt);
	i = 0;
    while (fmt[i])
	{
		if (fmt[i] == '%')
			if (in_managed_types(fmt[i + 1]))
			{
				if (result)
				{
					temp = ft_strdup(result);
					free(result);
					result = ft_strjoin(temp, get_string(fmt[i + 1], ap));
				}
			}
		i++;
	}
/*
    if(!ft_strcmp(fmt, "%d"))
    {
        int x =(int) va_arg (ap, int);
        ft_putnbr(x);
    }

    if(!ft_strcmp(fmt, "%s"))
    {
        char *p = va_arg (ap, char *);
        ft_putstr(p);
    }
*/
/*
    i = 0;
    while ((c = find_next(&fmt, ft_strlen(fmt))))
    {
        va_arg(ap, i);
        i++;
    }
*/

    va_end(ap);
	ft_putstr(result);
	return ((int)ft_strlen(result));
}