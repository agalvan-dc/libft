
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int	i;

	i = 0;
	p = (char *)s;
	c = (unsigned char)c;
		while (p[i])
			i++;
		while (i > 0)
		{
			if (p[i] == c)
				return (&p[i]);
			i--;
		}
	return (NULL);
}
