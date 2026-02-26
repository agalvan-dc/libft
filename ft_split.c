
#include "libft.h"

static char	**ft_fill(char **m, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (m[i][j])
	{
		while (s[k] != c)
		{
			m[i][j] = s[k];
			k++;
			j++;
		}
		j = 0;
		k++;
		i++;
	}
	m[i][j] = '\0';
	return (m);
}

static void	ft_create(char ***m, int n, int words)
{
	int		i;

	i = 0;
	(*m) = malloc(sizeof(char *) * words);
	if(*m == NULL)
		return ;
	while (i < words)
	{
		(*m)[i] = malloc(sizeof(char) * n);
		if ((*m)[i] == NULL)
			return ;
		i++;
	}
	return ;
}

static int		ft_countwords(char const *s, char c)
{
	int		cont;
	int		cont2;
	int		i;

	cont = 0;
	cont2 = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c)
			cont2++;
		if (cont2 > cont)
			cont = cont2;
		i = cont2 + 1;
		cont2 = 0;
	}
	return (cont);
}
static int		ft_check(char const *s)
{
	int		n;
	int		i;

	n = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13))
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		n;
	int		i;

	i = 0;
	n = ft_check(s);
	if (n == -1)
		return (NULL);
	n = 0;
	while(s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	i = ft_countwords(s, c);
	ft_create(&m, n + 1, i);
	m = ft_fill(m, s, c);
	return (m);
}
