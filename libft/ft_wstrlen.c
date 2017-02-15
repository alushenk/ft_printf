

#include "libft.h"

size_t		ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}