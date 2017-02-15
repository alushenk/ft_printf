/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcharn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:48:30 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/15 19:49:06 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getwcharlen(unsigned char c)
{
	int	len;

	len = 0;
	if (c >= 0 && c <= 127)
		len = 1;
	else if (c >= 192 && c <= 223)
		len = 2;
	else if (c >= 224 && c <= 239)
		len = 3;
	else if (c >= 240 && c <= 247)
		len = 4;
	else if (c >= 248 && c <= 251)
		len = 5;
	else if (c >= 252 && c <= 253)
		len = 6;
	return (len);
}

size_t			ft_putwcharn(char *s, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (s)
	{
		while (n)
		{
			if (len == 0)
				len = getwcharlen(s[i]);
			if (len > n)
				return (i);
			ft_putchar(s[i]);
			len--;
			n--;
			i++;
		}
	}
	return (i);
}
