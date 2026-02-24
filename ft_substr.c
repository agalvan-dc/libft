
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cad;
	size_t	i;

	i = len - (size_t)start;
	cad = malloc(sizeof(char) * (i + 1));
	if (cad == NULL)
		return (NULL);
	i = 0;
	while (start < len)
	{
		cad[i] = s[start];
		start++;
		i++;
	}
	cad[i] = '\0';
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_substr("Hello World, what", 4, 8));
	return (0);
}*/
