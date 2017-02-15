

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*result;
	size_t	size;
	size_t	i;

	result = NULL;
	if (s1)
	{
		size = len1 + len2;
		result = ft_strnew(size);
		if (result)
		{
			size = 0;
			while (len1--)
			{
				result[size] = s1[size];
				size++;
			}
			i = 0;
			while (len2--)
			{
				result[size] = s2[i];
				size++;
				i++;
			}
		}
	}
	return (result);
}