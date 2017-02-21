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

static int	read_string(t_format *format, va_list ap, char **s)
{
	if (format->size & L)
	{
		wstr_to_str(format, ap);
		*s = ft_strdup(format->sufix);
		free(format->sufix);
		return (1);
	}
	*s = va_arg(ap, char *);
	if (*s == NULL)
	{
		*s = ft_strdup("(null)");
		return (1);
	}
	return (0);
}

void		write_string(t_format *format, va_list ap)
{
	char	*s;
	int		is_null;

	s = NULL;
	if (format->precision == 0)
		return ;
	is_null = read_string(format, ap, &s);
	format->sufix_len = (int)ft_strlen(s);
	if (format->precision > 0 && format->sufix_len > format->precision)
		format->sufix_len = format->precision;
	format->sufix = ft_strnew(sizeof(char) * format->sufix_len);
	ft_strncpy(format->sufix, s, format->sufix_len);
	if (is_null)
		free(s);
}

void		write_char(t_format *format, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	format->sufix_len = 1;
	format->sufix = ft_strnew(1);
	if (c)
		format->sufix[0] = c;
	else
		format->sufix[0] = '\0';
}

static void	write_num_sufix(t_format *format, size_t num, int len)
{
	char	*mas;

	mas = (format->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	format->sufix = ft_strnew(sizeof(char) * len);
	format->sufix_len = len;
	while (--len >= 0)
	{
		format->sufix[len] = mas[num % format->base];
		num /= format->base;
	}
}

void		write_num(t_format *format, va_list ap)
{
	size_t	temp;
	int		i;

	if (format->size & U)
		format->num = cast_unsigned(format, ap);
	else
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
	write_num_sufix(format, format->num, i);
}
