/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:48:54 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/25 11:43:08 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

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
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	i = 0;
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
