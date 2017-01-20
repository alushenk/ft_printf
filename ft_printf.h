//
// Created by warto on 1/11/2017.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
/*
 * to use functions with multiple parametres
 */
#include <stdarg.h>
/*
 * stores the limits of the types for the different platforms
 */
#include <limits.h>

typedef struct 			s_format
{
	int		flag;
	int 	width;
	int 	precision;
	int		size;
	char 	type;

	char	*prefix;
	char 	*sufix;
}						t_format;

/*
 * additional functions
 */
int			ft_printf(char *fmt, ...);
void		initialise_struct(t_format **format);
/*
 * check functions
 */
int			check_flags(char **fmt, t_format *format);
int			check_width(char **fmt, va_list ap, t_format *format);
int			check_precision(char **fmt, va_list ap, t_format *format);
int			check_size(char **fmt, t_format *format);
void		check_type(char **fmt, t_format *format);
/*
 * output functions
 */
void		do_print(t_format *format, va_list ap);
void		write_string(t_format *format, va_list ap);
void		write_decimal(t_format *format, va_list ap);

#endif //FT_PRINTF_FT_PRINTF_H
