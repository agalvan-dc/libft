
#include "libft.h"
//#include <stdio.h>

char	*ft_fill(int cont, int i, char const *s1, char const *set)
{
	char	*str;
	int		j;
	int		k;

	j = 0;
	k = 0;
	str = malloc(sizeof(char) * (i - cont));
	if (str == NULL)
		return (NULL);
	while (set[j])
		j++;
	cont = j;
	while (s1[j] && j < (i - cont))
	{
		str[k] = s1[j];
		j++;
		k++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cad;
	int		i;
	int		j;
	int		cont;
	
	i = 0;
	j = 0;
	cont = 0;
	while (s1[i])
	{
		while (s1[j] && s1[j + i] == set[j])
		{	
			cont++;
			j++;
		}	
		i++;
	}
	cad = ft_fill(cont, i, s1, set);
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("ask Hola Mundo ask", "ask"));
	return (0);
}*/
