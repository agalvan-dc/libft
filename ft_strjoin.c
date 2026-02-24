
#include "libft.h"

char	*ft_fill(char *cad, int i, int j, char const *s1, char const *s2)
{
	int	k;

	k = 0;
	while (k < i)
	{
		cad[k] = s1[k];
		k++;
	}
	while (k < i + j)
	{
		cad[k] = s2[k - i];
		k++;
	}
	cad[i + j] = '\0';
	return (cad);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cad;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	cad = malloc(sizeof(char) * (i + j + 1));
	if (cad == NULL)
		return (NULL);
	cad = ft_fill(cad, i, j, s1, s2);
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("Hola", "Como estas"));
	return (0);
}*/ 
