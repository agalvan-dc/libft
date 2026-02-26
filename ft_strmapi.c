
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cad;
	int		i;

	i = 0;
	while (s[i])
		i++;
	cad = malloc(sizeof(char) * (i + 1));
	if (cad == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cad[i] = f(i, s[i]);
		i++;
	}
	cad[i] = '\0';
	return (cad);
}
