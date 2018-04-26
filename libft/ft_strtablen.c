#include "libft.h"

size_t		ft_strtablen(const char **tab)
{
	size_t len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	return (len);
}
