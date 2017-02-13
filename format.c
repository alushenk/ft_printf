/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:23:00 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 20:23:03 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_num_prefix(t_format *format)
{
	if (format->num_prefix[0] == 0 && (format->flag & SIGNED))
	{
		if (format->flag & PLUS)
			format->num_prefix[0] = '+';
		else if (format->flag & SPACE)
			format->num_prefix[0] = ' ';
	}
	if (format->num == 0 && format->precision == 0)
	{
		ft_bzero(format->sufix, format->sufix_len);
		format->sufix_len = 0;
	}
	if ((format->flag & HASH) || format->type == 'p')
	{
		if (format->base == 16 && (format->num != 0 || format->type == 'p'))
		{
			format->num_prefix[0] = '0';
			format->num_prefix[1] = (format->type == 'X') ? 'X' : 'x';
		}
		if (format->base == 8 && (format->precision <= format->sufix_len))
			format->num_prefix[0] = '0';
	}
}

void	format_num(t_format *f)
{
	ssize_t len;
	ssize_t	i;
	char	*str;

	i = ft_strlen(f->num_prefix);
	len = (f->precision > f->sufix_len) ? f->precision : f->sufix_len;
	if ((f->flag & ZEROPAD) && f->width > len &&
		f->precision == -1 && !(f->flag & LEFT))
		len = f->width - i;
	str = ft_strnew(len + 1);
	ft_strcat(str, f->num_prefix);
	while (f->sufix_len < len--)
	{
		str[i] = '0';
		i++;
	}
	f->sufix_len += i;
	ft_strcpy(str + i, f->sufix);
	free(f->sufix);
	f->sufix = str;
}

void	format_string(t_format *f)
{
	int		c;
	ssize_t	i;
	ssize_t len;
	char	*str;
	char	*temp;

	if ((len = f->width - f->sufix_len) <= 0)
		return ;
	f->sufix_len += len;
	c = (f->flag & ZEROPAD && !(f->flag & LEFT)) ? '0' : ' ';
	if (f->type != 'S' && f->type != 's' && f->precision != -1)
		c = ' ';
	str = ft_strnew(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	temp = ft_strdup(f->sufix);
	free(f->sufix);
	f->sufix = f->flag & LEFT ? ft_strjoin(temp, str) : ft_strjoin(str, temp);
	free(temp);
}
