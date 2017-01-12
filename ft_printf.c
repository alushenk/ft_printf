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

void    ft_printf(char *fmt, ...)
{
    va_list ap;
    va_list copy;
    size_t  i;
    char    c;


    if (!(count_outputs(fmt)))
    {
        ft_putendl(fmt);
        exit(0);
    }

    va_start(ap, fmt);
    if(!ft_strcmp(fmt, "%d"))
    {
        int x = va_arg (ap, int);
        printf ("You passed decimal object with value %d\n", x);
    }

    if(!ft_strcmp(fmt, "%s"))
    {
        char *p = va_arg (ap, char *);
        printf ("You passed c-string \"%s\"\n", p);
    }
/*
    i = 0;
    while ((c = find_next(&fmt, ft_strlen(fmt))))
    {
        va_arg(ap, i);
        i++;
    }
*/

    va_end(ap);


}