
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cad;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	cad = malloc(sizeof(char) * (i + j + 1));
	if (cad == NULL)
		return (NULL);
	while (k < i)
	{
		cad[k] = s1[k];
		k++;
	}
	while(k < i + j)
	{
		cad[k] = s2[k - i];
		k++;
	}
	cad[k] = '\0';
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("Hola", "Como estas"));
	return (0);
}*/ 
