/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:18:30 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 18:22:21 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_fill_w(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_wordlen(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_countwords(char const *s, char c)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			cont++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cont);
}

static char	**ft_fill_m(char **m, char const *s, char c, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		m[j] = ft_fill_w(&s[i], c);
		if (!m[j])
		{
			while (j - 1 >= 0)
				free(m[j--]);
			free(*m);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	m[j] = NULL;
	return (m);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		n;

	n = ft_countwords(s, c);
	m = malloc(sizeof(char *) * (n + 1));
	if (!m)
		return (NULL);
	return (ft_fill_m(m, s, c, n));
}
