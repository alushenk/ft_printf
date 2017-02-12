/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:18:02 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 20:18:07 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_string(t_format *format, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	format->sufix_len = (int)ft_strlen(s);

	if (format->precision > 0 && format->sufix_len > format->precision)
		format->sufix_len = format->precision;
	format->sufix = ft_strnew(sizeof(char) * format->sufix_len);
	ft_strncpy(format->sufix, s, format->sufix_len);
}

void	write_num(t_format *format, va_list ap)
{
	size_t		temp;
	char		*mas;
	int			i;

	mas = (format->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	format->num = cast_signed(format, ap);
	temp = 1;
	if ((format->flag & SIGNED) && (format->num & temp << 63))
	{
		if (format->base == 10)
			format->num_prefix[0] = '-';
		format->num = -format->num;
	}
	temp = format->num;
	i = (format->num) ? 0 : 1;
	while (temp > 0)
	{
		temp /= format->base;
		i++;
	}
	format->sufix = ft_strnew(sizeof(char) * i);
	format->sufix_len = i;
	temp = format->num;
	while (--i >= 0)
	{
		format->sufix[i] = mas[temp % format->base];
		temp /= format->base;
	}
}
