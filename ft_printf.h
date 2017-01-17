//
// Created by warto on 1/11/2017.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

typedef struct 			s_format
{
	int		flag;
	int 	width;
	int 	precision;
	char	*size;
}						t_format;

/*
 * печатать сразу или писать в заранее замалоченную строку статичного размера?
 */
int			g_count;
//int			g_flag;
t_format	*format;

int			ft_printf(char *fmt, ...);

int			check_flags(char *fmt, t_format *format);
int			check_width(char **fmt, va_list ap, t_format *format);
void		initialise_struct(t_format *format);
int			check_precision(char **fmt, va_list ap);
char		*check_size(char **fmt, va_list ap);


#endif //FT_PRINTF_FT_PRINTF_H
