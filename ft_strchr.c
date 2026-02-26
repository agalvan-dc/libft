
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int	i;

	i = 0;
	p = (char *)s;
	c = (char)c;
	while (p[i] && p[i] != c)
	{	
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (p[i] == c)
		return (&p[i]);
	return (NULL);
}
