#include "libft.h"

int		ft_isnumber(char *s)
{
	int i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}
