/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:56:33 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/15 19:56:37 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	cast_signed(t_format *format, va_list ap)
{
	size_t result;

	if (format->size & Z)
		result = va_arg(ap, size_t);
	else if (format->size & J)
		result = va_arg(ap, intmax_t);
	else if (format->size & LL)
		result = va_arg(ap, long long);
	else if (format->size & L)
		result = va_arg(ap, long);
	else if (format->size & H)
		result = (short)va_arg(ap, int);
	else if (format->size & HH)
		result = (char)va_arg(ap, int);
	else
		result = (size_t)va_arg(ap, int);
	return (result);
}

size_t	cast_unsigned(t_format *format, va_list ap)
{
	size_t result;

	if (format->size & Z)
		result = va_arg(ap, size_t);
	else if (format->size & J)
		result = va_arg(ap, uintmax_t);
	else if (format->size & LL)
		result = va_arg(ap, unsigned long long);
	else if (format->size & L)
		result = va_arg(ap, unsigned long);
	else if (format->size & H)
		result = (unsigned short)va_arg(ap, int);
	else if (format->size & HH)
		result = (unsigned char)va_arg(ap, int);
	else
		result = va_arg(ap, unsigned int);
	return (result);
}
