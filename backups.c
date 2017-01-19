//
// Created by Anton Lushenko on 1/19/17.
//
#include "ft_printf.h"

/*
char *check_size(char **fmt, va_list ap)
{
	char *str;
	char *result;

	result = NULL;
	str = *fmt;
	if (*str == 'h')
		result = ft_strdup("h");
	if (!strncmp(str, "hh", 2))
		result = ft_strdup("hh");
	if (*str == 'l')
		result = ft_strdup("l");
	if (!strncmp(str, "ll", 2))
		result = ft_strdup("ll");
	if (*str == 'j')
		result = ft_strdup("j");
	if (*str == 'z')
		result = ft_strdup("z");
	if (!result)
		return (NULL);
	str += ft_strlen(result);
	*fmt = str;
	return (result);
}
 */