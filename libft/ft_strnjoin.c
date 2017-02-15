/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:50:13 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/15 19:53:29 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*result;
	size_t	j;
	size_t	i;

	result = NULL;
	if (!s1)
		return (NULL);
	result = ft_strnew(len1 + len2);
	if (result)
	{
		j = 0;
		while (len1--)
		{
			result[j] = s1[j];
			j++;
		}
		i = 0;
		while (len2--)
		{
			result[j] = s2[i];
			j++;
			i++;
		}
	}
	return (result);
}
