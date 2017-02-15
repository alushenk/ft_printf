/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:49:40 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/15 19:49:55 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *s1)
{
	wchar_t *ptr;

	if (s1)
	{
		ptr = (wchar_t*)malloc(sizeof(wchar_t) * (ft_wstrlen(s1) + 1));
		if (ptr)
			return (ft_wstrcpy(ptr, s1));
	}
	return (NULL);
}
