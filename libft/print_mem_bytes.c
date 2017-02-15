/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:46:58 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/15 19:47:49 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_mem_bytes(void *adress, ssize_t size)
{
	char	*ptr;
	int		buf;
	int		mask;

	ptr = (char*)adress;
	ft_putstr("| ");
	while (--size >= 0)
	{
		buf = ptr[size];
		mask = 128;
		while (mask != 0)
		{
			if (buf & mask)
				ft_putchar('1');
			else
				ft_putchar('0');
			mask >>= 1;
		}
		ft_putstr(" | ");
	}
	ft_putchar('\n');
}
