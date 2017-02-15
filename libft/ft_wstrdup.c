

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