

#include "libft.h"

wchar_t		*ft_wstrcpy(wchar_t *dst, wchar_t *src)
{
	wchar_t	*ptr;

	ptr = dst;
	while (*src)
	{
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (ptr);
}