/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:41:03 by alushenk          #+#    #+#             */
/*   Updated: 2017/02/09 16:41:07 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		skip_atoi(char **s)
{
	size_t i;

	i = 0;
	while (ft_isdigit(**s))
	{
		i = i * 10 + *((*s)++) - '0';
		if (i > INT_MAX)
			return (INT_MAX);
	}
	return (i);
}

int		min_atoi(char *s)
{
	size_t i;

	i = 0;
	while (ft_isdigit(*s))
	{
		i = i * 10 + *s++ - '0';
		if (i > INT_MAX)
			return (INT_MAX);
	}
	return (i);
}

void	initialise_struct(t_format **format)
{
	if (!*format)
	{
		*format = (t_format *)malloc(sizeof(t_format));
		(*format)->prefix = NULL;
		(*format)->sufix = NULL;
		(*format)->num_prefix = ft_strnew(2);
	}
	(*format)->flag = 0;
	(*format)->width = 0;
	(*format)->precision = -1;
	(*format)->size = 0;
	(*format)->type = 0;
	(*format)->base = 10;
	(*format)->prefix_len = 0;
	(*format)->sufix_len = 0;
	if ((*format)->num_prefix)
		ft_bzero((*format)->num_prefix, 2);
	if ((*format)->prefix)
		free((*format)->prefix);
	(*format)->prefix = NULL;
	if ((*format)->sufix)
		free((*format)->sufix);
	(*format)->sufix = NULL;
	(*format)->num = 0;
}

void	add_symbol(t_format *format, char sym)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(format->sufix);
	temp = NULL;
	if (format->sufix)
	{
		temp = ft_strdup(format->sufix);
		free(format->sufix);
		format->sufix = ft_strnew(len + 1);
		ft_strcpy(format->sufix, temp);
	}
	else
		format->sufix = ft_strnew(1);
	*(format->sufix + len) = sym;
	format->sufix_len++;
	if (temp)
		free(temp);
}
