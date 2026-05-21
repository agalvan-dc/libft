/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:48:54 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 14:56:46 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static char	*ft_check(size_t end, const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (end + 1));
	if (str == NULL)
		return (NULL);
	while (i < end)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}*/

static int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cad;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (set[0] == '\0' || s1[0] == '\0')
		return (ft_strdup(s1));
	while (s1[start] && ft_set(s1[start], set))
		start++;
	while (end > start && ft_set(s1[end - 1], set))
		end--;
	cad = malloc(sizeof(char) * (end - start + 1));
	if (cad == NULL)
		return (NULL);
	while (start < end)
		cad[i++] = s1[start++];
	cad[i] = '\0';
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("ask Hola Mundo ask", "ask"));
	return (0);
}*/
